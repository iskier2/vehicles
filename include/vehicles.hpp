//
// Created by Iskra on 11.04.2024.
//

#ifndef VEHICLES_1_VEHICLES_HPP
#define VEHICLES_1_VEHICLES_HPP

#include <string>
#include <utility>
#include <vector>
#include <functional>
#include <cstdint>

class Vehicle{
public:
    Vehicle(std::string id, std::string brand) : vin_(vin_counter_++), id_(std::move(id)), brand_(std::move(brand)){};
    [[nodiscard]] std::string get_id() const {return id_;};
    Vehicle(Vehicle const& veh) = default;
    [[nodiscard]] std::string get_brand() const{return brand_;};
    [[nodiscard]] virtual double get_max_speed() const = 0;
    [[nodiscard]] std::int64_t get_vin()const{return vin_;};
    static void reset_vin_counter(){vin_counter_ = 1;}
    virtual ~Vehicle()= default ;
private:
    std::int64_t vin_;
    std::string id_;
    std::string brand_;
    inline static std::int64_t vin_counter_ = 1;
};
class Car:public Vehicle{
private:
    int engine_hp_;
public:
    Car(std::string id, std::string brand, double engine_hp): Vehicle(id, brand){engine_hp_ = engine_hp;};

    Car(Car const& car) = default;
    [[nodiscard]] double get_max_speed() const override;
};
class Bicycle:public Vehicle{
private:
    int n_gears_;
public:
    Bicycle(std::string id, std::string brand, int n_gears): Vehicle(id, brand){n_gears_ = n_gears;};

    Bicycle(Bicycle const& bicycle) = default;
    [[nodiscard]] double get_max_speed() const override;
};
std::string to_string(Vehicle& veh);

std::string to_string(std::vector<Vehicle*>::const_iterator vehicles_begin,
                      std::vector<Vehicle*>::const_iterator vehicles_end);

double compute_min_travel_duration(const double& distance, const Vehicle& vehicle);
std::string compute_min_travel_duration_as_string(const double& distance, const Vehicle& vehicle);
std::vector<Vehicle*> filter_vehicles(
        std::vector<Vehicle*>::const_iterator vehicles_begin,
        std::vector<Vehicle*>::const_iterator vehicles_end,
        std::function<bool (const Vehicle&)> predicate);

#endif //VEHICLES_1_VEHICLES_HPP
