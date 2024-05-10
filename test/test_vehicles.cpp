//
// Created by Iskra on 11.04.2024.
//
#include "gtest/gtest.h"

#include "vehicles.hpp"

TEST(CarTest, get_max_speed){
    Car car("KR 00001 ", "BMW", 3);
    EXPECT_EQ(car.get_max_speed(), 3);
}
TEST(BicycleTest, get_max_speed){
    Bicycle bicycle("0001", "cross", 1);
    EXPECT_EQ(bicycle.get_max_speed(), 3);
}
TEST(VehicleTest, toString){
    Car car("KR 00001", "BMW", 3);
    EXPECT_EQ(to_string(car), "KR 00001 : BMW");
}
TEST(VehicleAuxTest, computeMinTravelDuration){
    Bicycle bicycle("0001", "cross", 10);
    EXPECT_EQ(compute_min_travel_duration(15, bicycle), 0.5);
    EXPECT_EQ(compute_min_travel_duration_as_string(15, bicycle), "0.500 h");
    Car car("KR 00001", "BMW", 40);
    EXPECT_EQ(compute_min_travel_duration(80, car), 2);
    EXPECT_EQ(compute_min_travel_duration_as_string(80, car), "2.000 h");
}

TEST(VehiclesAlgorithms, filter){
    Car car1("KRC1", "a", 100.0);
    Car car2("CKR2", "b", 200.0);
    Bicycle bicycle("B1", "c", 0);

    std::vector<Vehicle*> vehicles = { &car1, &bicycle, &car2 };

    std::vector<Vehicle*> res = filter_vehicles(
            vehicles.begin(), vehicles.end(),
            [] (const Vehicle& a){
                std::string b = a.get_id();
                for( unsigned int i = 0; i < b.size() - 1; i++)
                    if(b[i] == 'K' && b[i + 1] == 'R') return true;
                return false;
            });
    EXPECT_EQ(res.size(), 2);
    EXPECT_EQ(res[0]->get_id(), vehicles[0]->get_id());
    EXPECT_EQ(res[1]->get_id(), vehicles[2]->get_id());
    std::cout<<to_string(vehicles.begin(), vehicles.end());
}
TEST(DriverAuxTest, assignVehicleToDriver) {
    std::vector<std::unique_ptr<Vehicle>> vehicles;
    vehicles.push_back(std::make_unique<Car>("KMY420", "Honda", 50));
    vehicles.push_back(std::make_unique<Bicycle>("1234", "cross", 10));
    Driver d("a", HELIKOPTER_BOJOWY);
    assign_vehicle_to_driver(vehicles, d);
    EXPECT_EQ(vehicles.size(), 1);
    EXPECT_EQ(d.get_vehicle()->get_id(), "1234");
}