

#include<iostream>
#include <string>
class  Plane {//Plane
private:

    int Range_of_flight;//Дальность полета
    int Pass_mest;
    int Takeoff_weight; //Взлетная масса
    int Empty_weight; //Масса пустого самолета
    int Wingspan;//Размах крыла
    std::string model;
    std::string name;
    int Crew_count;
    std::string Crew;//Экипаж

    // в наследование идет тип самолета (пассажирский, военный, спасательный, грузовой далее к ним присоединяются другие классы)
public:
    virtual void Ridedal() {
        if (Range_of_flight > 10000)
            std::cout << "Годен для дальних перелетов\n";
    }
};
class Safetyquipment : public Plane {//переименовать два в наследовании подвиды самолета
private:
    //std::string type;//тип самолета (пассажирский,спасательный,военный)
    bool Safety_equipment;//Спасательное оборудование
    //bool military_equipment;//Военное оборудование
    bool education_crew;


    int Range_of_flight;
    int Pass_mest;
    int Takeoff_weight;
    int Empty_weight;
    int Wingspan;
    std::string model;
    std::string name;
    int Crew_count;
    std::string Crew;

    Safetyquipment(int Range_of_flight, int Pass_mest, int Takeoff_weight, int Empty_weight,
        int Wingspan, std::string model, std::string name, int Crew_count, std::string Crew)
    {
        this->Range_of_flight = Range_of_flight;
        this->Pass_mest = Pass_mest;
        this->Takeoff_weight = Takeoff_weight;
        this->Empty_weight = Empty_weight;
        this->Wingspan = Wingspan;

        this->model = model;
        this->name = name;
        this->Crew_count = Crew_count;
        this->Crew = Crew;
    }
public:
    void print()
    {

        std::cout << "Range_of_flight       : " << this->Range_of_flight << std::endl;
        std::cout << " Pass_mest       : " << this->Pass_mest << std::endl;
        std::cout << "Takeoff_weight   : " << this->Takeoff_weight << std::endl;
        std::cout << "Empty_weight : " << this->Empty_weight << std::endl;
        std::cout << "Wingspan	     : " << this->Wingspan << std::endl;

        std::cout << "model       : " << this->model << std::endl;
        std::cout << " name       : " << this->name << std::endl;
        std::cout << "Crew_count   : " << this->Crew_count << std::endl;
        std::cout << "Crew : " << this->Crew << std::endl;


    }

    //полиморфный метод перевозка или работа делать что-то поразному метод get
    virtual void Ridedal() override{
        if (Range_of_flight > 10000)
            std::cout << "Годен для дальних перелетов\n";
    }




    std::string prov_Model()
    {
        std::string result;
        if (Safety_equipment == true)
            return result = "Пригоден для ЧС";
       /* if (military_equipment == true)
            return result = "Пригоден для ВС";*/
    }


};


class Militryaquipment: public Plane{//переименовать два в наследовании подвиды самолета
private:
    //std::string type;//тип самолета (пассажирский,спасательный,военный)
    bool military_equipment;//Спасательное оборудование
    //bool military_equipment;//Военное оборудование
    bool education_crew;


    int Range_of_flight;
    int Pass_mest;
    int Takeoff_weight;
    int Empty_weight;
    int Wingspan;
    std::string model;
    std::string name;
    int Crew_count;
    std::string Crew;

    Militryaquipment(int Range_of_flight, int Pass_mest, int Takeoff_weight, int Empty_weight,
        int Wingspan, std::string model, std::string name, int Crew_count, std::string Crew)
    {
        this->Range_of_flight = Range_of_flight;
        this->Pass_mest = Pass_mest;
        this->Takeoff_weight = Takeoff_weight;
        this->Empty_weight = Empty_weight;
        this->Wingspan = Wingspan;

        this->model = model;
        this->name = name;
        this->Crew_count = Crew_count;
        this->Crew = Crew;
    }
public:
    void print()
    {
        std::cout << "Range_of_flight       : " << this->Range_of_flight << std::endl;
        std::cout << " Pass_mest       : " << this->Pass_mest << std::endl;
        std::cout << "Takeoff_weight   : " << this->Takeoff_weight << std::endl;
        std::cout << "Empty_weight : " << this->Empty_weight << std::endl;
        std::cout << "Wingspan	     : " << this->Wingspan << std::endl;

        std::cout << "model       : " << this->model << std::endl;
        std::cout << " name       : " << this->name << std::endl;
        std::cout << "Crew_count   : " << this->Crew_count << std::endl;
        std::cout << "Crew : " << this->Crew << std::endl;
    }

int main()
{


    Safetyquipment RU(4, 8/*, 80, 87, 25, "Safe", "A-854ds6", 1, "ivanov I.I."*/);
    Safetyquipment GM(5, 8, 80, 87,25,"Safe", "A-854ds6", 1, "ivanov I.I.");
    Safetyquipment FR(4, 8, 80, 87, 65,"Safe", "A-854ds6", 1, "ivanov I.I.");
    Safetyquipment CN(0, 8, 80, 87, 88,"Safe", "A-854ds6", 1, "ivanov I.I.");


    RU.print();
    GM.print();
    FR.print();
    CN.print();

}
