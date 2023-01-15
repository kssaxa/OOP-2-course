
#include<iostream>
#include <string>
class  Characteristics_plane {
public:

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
    

};
class Plane : public Characteristics_plane {
public:
    std::string type;//тип самолета (пассажирский,спасательный,военный)
    bool Safety_equipment;//Спасательное оборудование
    bool military_equipment;//Военное оборудование


    ///////////Конструктор///////////
    //Plane() : Characteristics_plane() {};

    Plane(int Range_of_flight, int Pass_mest, int Takeoff_weight, int Empty_weight,
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

    std::string prov()
    {
        std::string result;
        if (Safety_equipment ==true )
            return result = "Пригоден для ЧС";
        if(military_equipment == true)
            return result = "Пригоден для ВС";
    }

};

int main()
{
    
    Characteristics_plane  RU(4, 8, 80, 87, "Safe", "A-854ds6", 1, "ivanov I.I.");
    Plane  GM(5, 8, 80, 87, "Safe", "A-854ds6", 1, "ivanov I.I.");
    Plane  FR(4, 8, 80, 87, "Safe", "A-854ds6", 1, "ivanov I.I.");
    Plane  CN(4, 8, 80, 87, "Safe", "A-854ds6", 1, "ivanov I.I.");
      

    /*RU.print();
    GM.print();
    FR.print();
    CN.print();*/

}
