/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include "MatrixList.h"

#include "functions.h"

MatrixList::MatrixList(std::string filename)
{
    char index;
    unsigned lines, columns;
    std::vector<float> matrixLine;
    std::string element;

    std::ifstream f;

    f.open(filename);
    if (!f)
    {
        std::cout << "FileNotFoundError: Unable to open file" << std::endl;
        exit(1); // terminate with error
    }

    std::string line;
    while (std::getline(f, line))
    {
        std::smatch match;
        std::regex pattern("^(.)\\s(\\d{1})\\s(\\d{1})$");
        if (!regex_search(line, match, pattern) && match.size() <= 0)
        {
            std::cout << "IndexError: First line of matrix file does not match" << std::endl;
            exit(1); // terminate with error
        }

        // If line is correct, uses a string stream to get
        // values from line (index, lines and columns)
        std::stringstream str(line);

        str >> index >> lines >> columns;

        for (int i = 0; i < lines; i++)
        {
            matrixLine.clear();
            for (int j = 0; j < columns; j++)
            {
                float number;
                f >> element;

                std::istringstream iss(element);
                iss >> number;

                if (iss.eof() && !iss.fail())
                {
                    matrixLine.push_back(number);
                }
                else
                {
                    std::cout << "ValueError: "
                              << "Element in position (" << i + 1 << ", "
                              << j + 1 << ") has invalid type." << std::endl;
                    exit(1); // terminate with error
                }
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

void MatrixList::clear()
{
    m_matrixList.clear();
}