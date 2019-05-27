#include <string>
#include <vector>

class Aluno
{
public:
    Aluno();

    Aluno(std::string, std::string, std::string, unsigned);

    std::string getName();
    std::string getDre();
    std::vector<float> getGrades();
    float getFrequency();
    std::string getCourse();
    unsigned getSemester();

    bool setGrade(unsigned, float);
    bool setFrequency(float);
    bool setCourse(std::string);
    bool setSemester(unsigned);

    float calculateFinalGrade();
    
    static float calculateAverage(float, float);

private:
    std::string name;
    std::string course;
    std::string dre;
    unsigned semester;
    std::vector<float> grades;
    std::vector<float> gradesAverage;
    float finalGrade;
    float frequency;
};