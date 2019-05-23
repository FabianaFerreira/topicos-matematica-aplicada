/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include "MatrixList.h"

#include "functions.h"

MatrixList::MatrixList(std::string filename)
{
    unsigned lines, columns, lineCounter, linesInFile;
    std::vector<float> matrixLine;
    std::string element;
    std::ifstream f;
    std::string line;

    f.open(filename);
    linesInFile = getFileLinesQuantity(filename);

    lineCounter = 0;

    if (!f)
    {
        std::cout << "FileNotFoundError: Unable to open file" << std::endl;
        exit(1); // terminate with error
    }

    while (std::getline(f, line))
    {

        if (lineCounter == 0)
        {
            std::smatch match;
            std::regex pattern("^(\\d+)\\s(\\d+)$");
            if (!regex_search(line, match, pattern) && match.size() <= 0)
            {
                std::cout << "IndexError: First line of matrix file does not match" << std::endl;
                exit(1); // terminate with error
            }

            std::vector<unsigned> dimensions(getNumbersFromString(line));

            lines = dimensions.at(0);
            columns = dimensions.at(1);

            /*Removing first line*/
            if (lines != linesInFile - 1)
            {
                std::cout << "IndexError: Number of lines does not match" << std::endl;
                exit(1); // terminate with error
            }
        }
        else
        {
            for (int i = 0; i < lines; i++)
            {
                matrixLine.clear();
                if (line.length() != 2 * columns - 1)
                {
                    std::cout << "IndexError: Number of columns does not match" << std::endl;
                    exit(1); // terminate with error
                }
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
                m_matrixList[lineCounter].push_back(matrixLine);
            }
        }

        lineCounter++;
    }

    f.close();
};

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