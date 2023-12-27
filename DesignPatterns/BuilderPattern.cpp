#include<iostream>
#include<vector>
using namespace std;


class House{
private:
vector<string> house_feature;
public:
    void addWalls(){
        house_feature.push_back("wall");
    }
    void addRoof(){
        house_feature.push_back("roof");
    }
    void addPool(){
        house_feature.push_back("pool");
    }
    void addGarden(){
        house_feature.push_back("garden");
    }
    void getHouseFeature(){
        for(int i=0;i<house_feature.size();i++){
            cout<<house_feature[i]<<" ";
        }
        cout<<endl;
    }
};

class HouseBuilder{
private:
    House* house;

public:
    HouseBuilder(){
        house = new House();
    }
    HouseBuilder& addWalls(){
        house->addWalls();
        return *this;
    }
    HouseBuilder& addRoof(){
        house->addRoof();
        return *this;
    }
    HouseBuilder& addGarden(){
        house->addGarden();
        return *this;
    }
    HouseBuilder& addPool(){
        house->addPool();
        return *this;
    }
    House* build(){
        House* built_house = this->house;
        this->house = new House();
        return built_house;
    }
};

int main(){

    HouseBuilder houseBuilder;
    House* house1 = houseBuilder.addRoof().addWalls().build();
    House* house2 = houseBuilder.addRoof().addWalls().addGarden().build();
    house1->getHouseFeature();
    house2->getHouseFeature();
    return 0;

}