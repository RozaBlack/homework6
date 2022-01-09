// homework6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <iostream>

// functions for task 1
size_t getSizeArrow();
int* createArrow(size_t);
void fillArrow(int*, size_t);
void printArr(int*, size_t);
void deleteArr(int*);

// functions for task 2
int** createMatrix(size_t, size_t);
int** createMatrixColumn(size_t);
int* createMatrixRow(size_t);
void fillMatrix(int**, size_t, size_t);
void printMatrix(int**, size_t, size_t);
void deleteMatrix(int**, size_t);

// functions for task 2 variant 2
// int* createArrow(size_t); // from the task 1
// void deleteArr(int*); // from the task 1
void fillMatrix(int*, size_t);
void printMatrix(int*, size_t, size_t);

//functions fot tasks 3 and 4
std::string getFileName();
void createFile(std::string, std::string);
void mergeFiles(std::string, std::string, std::string);
// void writeToFile(std::ofstream*, std::string);

// function for task 5
std::string getWord();
void findWordInFile(std::string, std::string);
bool findWordInString(std::string, std::string);

int main()
{
    // task 1
    { 
        size_t sizeArr = 0;
        int* massive;

        sizeArr = getSizeArrow();
        massive = createArrow(sizeArr);
        fillArrow(massive, sizeArr);
        printArr(massive, sizeArr);
        deleteArr(massive);
    }
    std::cout << std::endl;

    // task 2
    {
        size_t matrixHeight = 4;
        size_t matrixWidth = 4;
        int** matrix;

        matrix = createMatrix(matrixHeight, matrixWidth);
        fillMatrix(matrix, matrixHeight, matrixWidth);
        printMatrix(matrix, matrixHeight, matrixWidth);
        deleteMatrix(matrix, matrixWidth);

    }
    std::cout << std::endl;

    //task 2 variant 2
    {
        size_t matrixHeight = 4;
        size_t matrixWidth = 4;
        size_t matrixSize = matrixHeight * matrixWidth;
        int* matrix;

        matrix = createArrow(matrixSize);
        fillMatrix(matrix, matrixSize);
        printArr(matrix, matrixSize);
        printMatrix(matrix, matrixHeight, matrixWidth);
        deleteArr(matrix);

    }
    std::cout << std::endl;

    
    {
        // task 3

        std::string text1 = "Hanyu is the first Japanese male skater to win Olympic gold and the first man\nsince 1948 and 1952 Olympic Chammpion Dick Button to win back - to - back Olympic gold medals.\nHe is the first skater to perform a clean quadruple loop in competition.\nHanyu became the first skater to surpass a total score of 300 points.\nHanyu followed his older sister Saya into skating.";
        std::string text2 = "Hanyu's home and ice rink were damaged during the earthquake and tsunami catastrophe on March 11, 2011\nand he trained in Yokohama before the icerink reopened four months later.\nHanyu moved to Canada for training inspring 2012.\nHanyu has contributed significantly to the choreography of hisprograms in the 2020 / 21 season.";

        std::string fileName1 = getFileName();
        std::string fileName2 = getFileName();

        createFile(fileName1, text1);
        createFile(fileName2, text2);

        // task 4

        std::string fileName3 = getFileName();
        mergeFiles(fileName1, fileName2, fileName3);

        // task 5
        std::string hiddenWord = getWord();
        findWordInFile(hiddenWord, fileName3);
    }

    return 0;
}

// functions for task 1
int* createArrow(size_t SizeArr)
{
    return new (std::nothrow) int[SizeArr];
}

size_t getSizeArrow()
{
    size_t sizeArr;
    std::cout << "Enter size of array: ";
    std::cin >> sizeArr;
    
    return sizeArr;
}

void fillArrow(int* massive, size_t sizeArr)
{
    
    for (size_t i = 0; i < sizeArr; i++)
    {
        massive[i] = 1 << i;
    }
}

void printArr(int* massive, size_t sizeArr)
{
    for (size_t i = 0; i < sizeArr; i++)
    {
        std::cout << massive[i] << " ";
    }
    std::cout << std::endl;
}

void deleteArr(int* massive)
{
    delete[] massive;
    massive = nullptr;
}

// functions for task 2
int** createMatrix(size_t matrixHeight, size_t matrixWidth)
{
    int** matrix = createMatrixColumn(matrixHeight);
    for (size_t i = 0; i < matrixHeight; i++)
    {
        matrix[i] = createMatrixRow(matrixWidth);
    }
    return matrix;
}

int** createMatrixColumn(size_t matrixHeight)
{
    return new (std::nothrow) int* [matrixHeight];
}

int* createMatrixRow(size_t matrixWidth)
{
    return new (std::nothrow) int[matrixWidth];
}

void fillMatrix(int** matrix, size_t matrixHeight, size_t matrixWidth)
{
    for (size_t i = 0; i < matrixHeight; i++)
    {
        for (size_t j = 0; j < matrixWidth; j++)
        {
            matrix[i][j] = rand() % 100 - 50;
        }
    }
}

void printMatrix(int** matrix, size_t matrixHeight, size_t matrixWidth)
{
    for (size_t i = 0; i < matrixHeight; i++)
    {
        for (size_t j = 0; j < matrixWidth; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void deleteMatrix(int** matrix, size_t matrixWidth)
{
    for (size_t i = 0; i < matrixWidth; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;
}

// functions for task 2 variant 2
void fillMatrix(int* matrix, size_t matrixSize)
{
    for (size_t i = 0; i < matrixSize; i++)
    {
        matrix[i] = rand() % 100 - 50;
    }
}

void printMatrix(int* matrix, size_t matrixHeight, size_t matrixWidth)
{
    for (size_t i = 0; i < matrixHeight; i++)
    {
        for (size_t j = i * matrixWidth; j < (i+1) * matrixWidth; j++)
        {
            std::cout << matrix[j] << " ";
        }
        std::cout << std::endl;
    }
}

//functions fot tasks 3 and 4
std::string getFileName()
{
    std::string fileName;
    std::cout << "Enter the file name: ";
    std::cin >> fileName;

    return fileName;
}

void createFile(std::string fileName, std::string text)
{
    std::ofstream fout;
    fout.open(fileName);
    fout << text << std::endl;
    fout.close();
}


void mergeFiles(std::string file1, std::string file2, std::string file3)
{
    const size_t size = 255;
    char buf[size];
    bool flag = false;

    std::ofstream resultFile(file3);

    std::ifstream firstFile(file1);

    if (firstFile.is_open())
    {
        while (!firstFile.eof())
        {
            firstFile.getline(buf, size);
            resultFile << buf << std::endl;
        }
        firstFile.close();
        flag = true;
    }
    
    if (flag == true)
    {
        std::ifstream secondFile(file2);

        if (secondFile.is_open())
        {
            while (!secondFile.eof())
            {
                secondFile.getline(buf, size);
                resultFile << buf << std::endl;
            }
            secondFile.close();
            flag = true;
        }
        else 
        {
            flag = false;
        }
    }

    resultFile.close();
    if (flag == false)
    {
        std::cout << "Something went wrong. File merging failed" << std::endl;
    }
}

// functions for task 5
std::string getWord()
{
    std::string word;
    std::cout << "Enter a world you want to find: ";
    std::cin >> word;

    return word;
}

void findWordInFile(std::string word, std::string fileName)
{
    const size_t size = 255;
    char buf[size];
    std::string fileString;
    bool flag = false;

    std::ifstream file(fileName);

    if (file.is_open())
    {
        while (!file.eof())
        {
            file.getline(buf, size);
            fileString = std::string(buf);
            //std::cout << fileString << std::endl;
            flag = findWordInString(word, fileString);
            if (flag == true)
            {
                std::cout << "Your word has been found" << std::endl;
                break;
            }
        }
        
        if (flag == false)
        {
            std::cout << "Your word hasn't been found" << std::endl;
        }

        file.close();
    }
}

bool findWordInString(std::string word, std::string fileString)
{
    bool flag = false;
    if (fileString.find(word) != std::string::npos)
    {
        flag = true;
    }
    else
    {
        flag = false;
    }

    return flag;
}