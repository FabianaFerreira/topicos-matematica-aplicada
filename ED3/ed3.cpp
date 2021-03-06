/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include <iostream>
#include <fstream>
#include <sstream>

#include <string>
#include <vector>

#include <stdlib.h>
#include <stdio.h>

#include "functions.h"
#include "MatrixList.h"

using namespace std;

/*--------------------------------------------- MAIN -------------------------------------------------------*/
int main()
{
	char index;
	string input;
	string filename;
	cout << "Digite o nome da lista de matrizes a ser lido (.txt): ";
	cin >> filename;
	cout << endl
		 << endl;

	MatrixList matrixList(filename);

	Matrix *result;
	Matrix *m1;
	Matrix *m2;

	printMenu();

	//Ignoring \n that is in buffer
	cin.ignore();

	while (input.compare("exit") != 0)
	{
		cout << "Digite uma opcao: ";
		getline(cin, input);

		switch (atoi(input.c_str()))
		{
		/*Soma ou subtração*/
		case 1:
		{

			char index2, sub;
			cout << "Digite o identificador da primeira matriz: ";
			cin >> index;

			cout << "Digite o identificador da segunda matriz: ";
			cin >> index2;

			cout << "Eh substracao? (y/n): " << endl;
			cin >> sub;

			int isSub = getUserOption(sub);

			//In case of getUserOption throwing -1 as result -> invalid option
			if (isSub == -1)
			{
				cout << "Opcao invalida" << endl;
			}
			else
			{
				//Copy constructor
				m1 = matrixList.get(index);

				//Copy constructor
				m2 = matrixList.get(index2);

				if (m1->getLines() == m2->getLines() && m1->getColumns() == m2->getColumns())
				{
					if (isSub == 1)
					{
						result = *m1 - *m2;
					}
					else if (isSub == 0)
					{
						result = *m1 + *m2;
					}

					cout << "Resultado: " << endl;

					printMatrix(result->getMatrix());
				}

				else
					cout << "Dimensoes da matriz 1 sao diferentes da matriz 2. Nao eh possivel realizar a operacao" << endl;
			}
		}
		break;

		/*Multiplicação por escalar*/
		case 2:
		{
			float scalar;

			cout << "Digite o identificador da primeira matriz: ";
			cin >> index;

			cout << "Digite o escalar: " << endl;
			cin >> scalar;

			result = *matrixList.get(index) * scalar;

			cout << "** Resultado **" << endl;
			printMatrix(result->getMatrix());
			cout << endl;
		}

		break;

		/*Multiplicação matricial*/
		case 3:
		{
			char index2;

			cout << "Digite o identificador da primeira matriz: ";
			cin >> index;

			cout << "Digite o identificador da segunda matriz: ";
			cin >> index2;

			//Copy constructor
			m1 = matrixList.get(index);

			//Copy constructor
			m2 = matrixList.get(index2);

			if (m1->getLines() == m2->getColumns())
			{
				result = *matrixList.get(index) * (*matrixList.get(index2));
			}
			else
			{
				cout << "Numero de linhas da matriz 1 eh diferente do numero de colunas da matriz 2. Nao eh possivel realizar a operacao" << endl;
				break;
			}
			cout << "** Resultado **" << endl;
			printMatrix(result->getMatrix());
			cout << endl;
		}
		break;

		/*Transposição*/
		case 4:
		{
			cout << "Digite o identificador da matriz: ";
			cin >> index;

			matrixList.get(index)->transpose();

			cout << "** Resultado **" << endl;
			printMatrix(matrixList.get(index)->getMatrix());
			cout << endl;
		}
		break;

		/*Determinante de uma matriz triangular*/
		case 5:
		{
			cout << "Digite o identificador da matriz: ";
			cin >> index;

			const UpperTriangularMatrix *pointer1 = dynamic_cast<const UpperTriangularMatrix *>(matrixList.get(index));

			const LowerTriangularMatrix *pointer2 = dynamic_cast<const LowerTriangularMatrix *>(matrixList.get(index));

			if (!pointer1 && !pointer2)
			{
				cout << "A matriz selecionada nao eh triangular" << endl;
			}
			else
			{
				float determinant = 0;
				if (pointer1)
				{
					UpperTriangularMatrix matrix = *pointer1;
					determinant = matrix.calculateDeterminant();
				}

				else if (pointer2)
				{
					LowerTriangularMatrix matrix = *pointer2;
					determinant = matrix.calculateDeterminant();
				}

				cout << "** Resultado **" << endl;
				cout << "Determinante: " << determinant << endl;
				cout << endl;
			}
			break;
		}

		/*Traco de uma matriz quadrada*/
		case 6:
		{
			cout << "Digite o identificador da matriz: ";
			cin >> index;

			const SquareMatrix *pointer = dynamic_cast<const SquareMatrix *>(matrixList.get(index));

			if (!pointer)
			{
				cout << "A matriz selecionada nao eh quadrada" << endl;
			}
			else
			{
				SquareMatrix matrix = *pointer;
				float trace = matrix.calculateTrace();

				cout << "** Resultado **" << endl;
				cout << "Traco: " << trace << endl;
				cout << endl;
			}
		}
		break;

			/*Imprimir uma ou mais matrizes da lista*/
		case 7:
		{
			std::string id;
			cout << "Digite o(s) identificador(es) da(s) matriz(es) a ser(em) listada(s) separados por espaco: ";
			getline(std::cin, id);
			vector<string> identifiers(parseInput(id, ' '));
			for (unsigned i = 0; i < identifiers.size(); i++)
			{
				char ident = identifiers.at(i).c_str()[0];
				cout << "** Matrix " << ident << " **" << endl;
				printMatrix(matrixList.get(ident)->getMatrix());
				cout << endl;
			}
		}
		break;

		/*Inserir matriz qualquer*/
		case 8:
		{
			unsigned lines, columns;
			cout << "Digite uma letra para identificar a nova matriz: ";
			cin >> index;
			cin.ignore();

			std::cout << "Digite a quantidade de linhas da matriz: ";
			std::cin >> lines;
			std::cin.ignore();
			std::cout << lines << " linhas" << std::endl;

			std::cout << "Digite a quantidade de colunas da matriz: ";
			std::cin >> columns;
			std::cin.ignore();
			std::cout << columns << " colunas" << std::endl;

			matrixList.insert(index, new Matrix(lines, columns, getMatrixFromUser(lines, columns)));

			cout << endl;
			cout << "Lista alterada com sucesso!" << endl;
			cout << endl;

			cout << "** -- Lista atual -- **" << endl;
			matrixList.list();
			cout << "** ----------------- **" << endl;
			cout << endl;
		}
		break;

		/*Inserir matriz identidade n x n*/
		case 9:
		{
			char identifier;
			unsigned dimension;
			cout << "Digite o identificador da matriz a ser inserida: ";
			cin >> identifier;

			cout << "Digite a dimensao da matriz identidade a ser inserida: ";
			cin >> dimension;

			matrixList.insertIdentity(identifier, dimension);
			matrixList.list();
		}
		break;

		/*Alterar ou remover uma ou mais matrizes da lista*/
		case 10:
		{
			std::string id;
			char option;
			bool removes = false;
			cout << "Digite o(s) identificador(es) da(s) matriz(es) a ser(em) listada(s) separados por espaco: ";
			getline(cin, id);
			vector<string> identifiers(parseInput(id, ' '));

			for (unsigned i = 0; i < identifiers.size(); i++)
			{
				unsigned lines, columns;
				char ident = identifiers.at(i).c_str()[0];
				cout << "Voce deseja alterar a matriz " << ident << "? (y/n). Se nao, voce ira remove-la. ";
				cin >> option;

				if (getUserOption(option) == -1)
				{
					cout << "Opcao invalida" << endl;
					break;
				}
				removes = getUserOption(option) == 0 ? true : false;

				if (removes)
				{
					matrixList.remove(ident);
					cout << "Matriz " << ident << " removida com sucesso!" << endl;
					matrixList.save(filename);
				}
				else
				{
					cout << "Voce optou por alterar a matriz " << ident << "." << endl;
					cout << endl;

					std::cout << "Digite a quantidade de linhas da matriz: ";
					std::cin >> lines;
					std::cin.ignore();
					std::cout << lines << " linhas" << std::endl;

					std::cout << "Digite a quantidade de colunas da matriz: ";
					std::cin >> columns;
					std::cin.ignore();
					std::cout << columns << " colunas" << std::endl;

					matrixList.insert(ident, new Matrix(lines, columns, getMatrixFromUser(lines, columns)));
					matrixList.save(filename);
				}
				cout << endl;
			}

			cout << endl
				 << "Lista alterada com sucesso!" << endl;
			cout << endl;
			matrixList.list();
			cin.ignore();
		}
		break;

		/*Lista todas as matrizes*/
		case 11:
		{
			matrixList.list();
		}
		break;

		/*Fazer backup*/
		case 12:
		{
			string filename;
			cout << "Digite o nome do arquivo de backup: ";
			cin >> filename;

			matrixList.save(filename);

			cout << endl;
			cout << "Arquivo criado com sucesso" << endl;
		}
		break;

		/*Alterar arquivo de matrizes*/
		case 13:
		{
			string filename;
			char option;
			cout << "Digite o nome do arquivo a ser lido: ";
			cin >> filename;

			cout << "Voce deseja sobrescrever o arquivo? (y/n). Se nao, sera adicionado ao fim do arquivo existente" << endl;
			cin >> option;

			if (getUserOption(option) == -1)
			{
				cout << "Opcao invalida" << endl;
				break;
			}
			bool appends = getUserOption(option) == 0 ? true : false;

			matrixList.readFile(filename, appends);
			matrixList.save("matrix.txt");

			cout << endl;
			cout << "Arquivo alterado com sucesso" << endl;
		}
		break;

		/*Zera lista*/
		case 14:
		{
			matrixList.clear();
			matrixList.save("matrix.txt");

			cout << endl;
			cout << "Arquivo zerado com sucesso" << endl;
		}
		break;

		default:
		{
			if (!input.compare("exit") == 0)
				cout << "Opcao invalida. Por favor, tente novamente." << endl;
		}
		break;
		}
		// cin.ignore();
	}
	cout << "Obrigada por testar!" << endl;

	// if (result != NULL)
	// {
	// 	delete result;
	// }

	// if (m1 != NULL)
	// {
	// 	delete m1;
	// }

	// if (m2 != NULL)
	// {
	// 	delete m2;
	// }

	return 0;
}
