#include <string>
#include <vector>

class Aluno
{
public:
    Aluno(std::string, std::string, std::string, unsigned, float, std::vector<float>);
    Aluno(std::string, std::string = "Sem nome", std::string = "Sem curso", unsigned = 0, float = 0);
    ~Aluno();

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

    void printData() const;
    static float calculateAverage(float, float);

private:
    std::string name;
    std::string course;
    std::string dre;
    unsigned semester;
    float frequency;
    std::vector<float> grades;
};
