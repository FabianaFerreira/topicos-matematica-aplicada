#include "MatrixList.h"

#include "functions.h"

MatrixList::MatrixList()
{
    std::cout << "Construtor padrao" << std::endl;
    ;
};

MatrixList::MatrixList(std::string filename)
{
    char index;
    unsigned lines, columns;
    std::vector<float> matrixLine;
    float element;

    // std::cout << "Construtor com arquivo definido pelo usu[ár" << std::endl;
    std::ifstream f;

    f.open(filename);
    if (!f)
    {
        std::cout << "Unable to open file" << std::endl;
        exit(1); // terminate with error
    };

    while (!f.eof())
    {
        f >> index >> lines >> columns;
        for (int i = 0; i < lines; i++)
        {
            matrixLine.clear();
            for (int j = 0; j < columns; j++)
            {
                f >> element;
                matrixLine.push_back(element);
            }
            m_matrixList[index].push_back(matrixLine);
        }
    }

    f.close();
};

// Read matrix list from file. If `append` is true, then append the new
// matrix list content to the current one, overwriting existing indexes.
// If `append` is false, set the matrix list content to the file data.
void MatrixList::readFile(std::string filename, bool append = false)
{
    char index;
    unsigned lines, columns;
    std::vector<float> matrixLine;
    std::map<char, Matrix> tempMatrixList;
    float element;
    bool wasEmpty = (m_matrixList.size() == 0);

    std::cout << "Construtor arquivo" << std::endl;
    std::ifstream f;

    f.open(filename);
    if (!f)
    {
        std::cout << "Unable to open file";
        exit(1); // terminate with error
    };

    while (!f.eof())
    {
        f >> index >> lines >> columns;
        for (int i = 0; i < lines; i++)
        {
            matrixLine.clear();
            for (int j = 0; j < columns; j++)
            {
                f >> element;
                matrixLine.push_back(element);
            }
            if (append || wasEmpty)
                m_matrixList[index].push_back(matrixLine);
            else
                tempMatrixList[index].push_back(matrixLine);
        }
    }

    f.close();

    if (!append)
        m_matrixList = tempMatrixList;
}

void MatrixList::save(std::string filename)
{
    std::ofstream f;

    f.open(filename);
    if (!f)
    {
        std::cout << "Unable to open file";
        exit(1); // terminate with error
    };

    unsigned counter = 0;
    for (auto const &x : m_matrixList)
    {
        Matrix matrix = x.second;
        unsigned lines = matrix.size();
        unsigned columns = matrix[0].size();

        f << x.first << " " << lines << " " << columns << std::endl;
        for (unsigned i = 0; i < lines; i++)
        {
            for (unsigned j = 0; j < columns; j++)
            {
                f << matrix.at(i).at(j);
                if (j != (columns - 1))
                    f << " ";
            }
            if ((i != (lines - 1)) || (counter != (m_matrixList.size() - 1)))
                f << std::endl;
        }
        if (counter != (m_matrixList.size() - 1))
            f << std::endl;

        counter++;
    }

    f.close();
}

void MatrixList::list()
{
    if (m_matrixList.size() == 0)
    {
        std::cout << "Empty matrix list" << std::endl;
        return;
    }

    for (auto const &x : m_matrixList)
    {
        Matrix matrix = x.second;
        unsigned lines = matrix.size();
        unsigned columns = matrix[0].size();

        std::cout << "Matrix " << x.first << " (" << lines << "," << columns << ")\n";
        printMatrix(matrix);
        std::cout << std::endl;
    }
}

Matrix MatrixList::get(char index)
{
    return m_matrixList[index];
}

// Add or modify a matrix of the list given an index
void MatrixList::insert(char index, Matrix newMatrix)
{
    m_matrixList[index] = newMatrix;
}

// Add a identify of dimension 'n x n' on a given index
void MatrixList::insertIdentity(char index, unsigned n)
{
    Matrix identity;
    for (unsigned i = 0; i < n; i++)
    {
        identity.push_back(std::vector<float>(n, 0));
        identity.at(i).at(i) = 1;
    }
    this->insert(index, identity);
}

void MatrixList::remove(char index)
{
    m_matrixList.erase(index);
}

void MatrixList::clear()
{
    m_matrixList.clear();
}