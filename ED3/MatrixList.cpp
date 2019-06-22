/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include "MatrixList.h"
#include "functions.h"

MatrixList::MatrixList(){};

MatrixList::MatrixList(std::string filename)
{
    char index, type;
    unsigned lines, columns;
    std::vector<float> matrixLine;
    float element;

    std::ifstream f;

    f.open(filename);
    if (!f)
    {
        std::cout << "Unable to open file" << std::endl;
        exit(1); // terminate with error
    };

    while (!f.eof())
    {
        f >> index >> lines >> columns >> type;

        TypeMatrix m;

        for (int i = 0; i < lines; i++)
        {
            matrixLine.clear();
            for (int j = 0; j < columns; j++)
            {
                f >> element;
                matrixLine.push_back(element);
            }
            m.push_back(matrixLine);
        }

        switch (type)
        {
        case 'g':
            std::cout << "geral" << std::endl;
            insert(index, new Matrix(lines, columns, m));
            break;

        case 'd':
            insert(index, new DiagonalMatrix(lines, columns, m));
            break;

        case 's':
            insert(index, new SquareMatrix(lines, columns, m));
            break;

        case 'u':
            insert(index, new UpperTriangularMatrix(lines, columns, m));
            break;

        case 'l':
            insert(index, new LowerTriangularMatrix(lines, columns, m));
            break;

        default:
            std::cout << "There is a matrix with an unknown type" << std::endl;
            exit(2);
            break;
        }
    }

    f.close();
};

MatrixList::~MatrixList()
{
    for (auto &x : m_matrixList)
    {
        delete x.second;
    }
}

// Read matrix list from file. If `append` is true, then append the new
// matrix list content to the current one, overwriting existing indexes.
// If `append` is false, set the matrix list content to the file data.
void MatrixList::readFile(std::string filename, bool append = false)
{
    char index, type;
    unsigned lines, columns;
    std::vector<float> matrixLine;
    std::map<char, Matrix *> tempMatrixList;
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
        TypeMatrix m;
        TypeMatrix temp;

        f >> index >> lines >> columns >> type;
        for (int i = 0; i < lines; i++)
        {
            matrixLine.clear();
            for (int j = 0; j < columns; j++)
            {
                f >> element;
                matrixLine.push_back(element);
            }
            m.push_back(matrixLine);
        }

        //m
        // switch (type)
        // {
        // case 'g':
        //     if
        //     append || wasEmpty ? m_matrixList[index] = Matrix(lines, columns, m) : tempMatrixList[index] = Matrix(lines, columns, m);
        //     break;

        // case 'd':
        //     append || wasEmpty ? m_matrixList[index] = DiagonalMatrix(lines, columns, m) : tempMatrixList[index] = DiagonalMatrix(lines, columns, m);
        //     break;

        // case 's':
        //     append || wasEmpty ? m_matrixList[index] = SquareMatrix(lines, columns, m) : tempMatrixList[index] = SquareMatrix(lines, columns, m);
        //     break;

        // case 'u':
        //     append || wasEmpty ? m_matrixList[index] = UpperTriangularMatrix(lines, columns, m) : tempMatrixList[index] = UpperTriangularMatrix(lines, columns, m);
        //     break;

        // case 'l':
        //     append || wasEmpty ? m_matrixList[index] = LowerTriangularMatrix(lines, columns, m) : tempMatrixList[index] = LowerTriangularMatrix(lines, columns, m);
        //     break;

        // default:
        //     break;
        // }

        // if (append || wasEmpty)
        //     m_matrixList[index].push_back(m);
        // else
        //     tempMatrixList[index].push_back(m);
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
        TypeMatrix matrix = x.second->getMatrix();
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

    for (auto x : m_matrixList)
    {
        unsigned lines = x.second->getLines();
        unsigned columns = x.second->getColumns();

        std::cout << "Matrix " << x.first << " (" << lines << "," << columns << ")\n";
        printMatrix(x.second->getMatrix());
        std::cout << std::endl;
    }
}

Matrix *MatrixList::get(char index)
{
    return m_matrixList[index];
}

// Add or modify a matrix of the list given an index
void MatrixList::insert(char index, Matrix *newMatrix)
{
    m_matrixList[index] = newMatrix;
}

// Add a identify of dimension 'n x n' on a given index
void MatrixList::insertIdentity(char index, unsigned n)
{
    TypeMatrix identity;
    for (unsigned i = 0; i < n; i++)
    {
        identity.push_back(std::vector<float>(n, 0));
        identity.at(i).at(i) = 1;
    }

    this->insert(index, new DiagonalMatrix(n, n, identity));
}

void MatrixList::remove(char index)
{
    m_matrixList.erase(index);
}

void MatrixList::clear()
{
    m_matrixList.clear();
}