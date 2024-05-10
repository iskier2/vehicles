//
// Created by Iskra on 11.04.2024.
//
#include <iomanip>
#include "vehicles.hpp"
double Car::get_max_speed() const {
    return engine_hp_;
}
double Bicycle::get_max_speed() const {
    return 3 * n_gears_;
}
std::string to_string(Vehicle& veh){
    return veh.get_id() + " : " + veh.get_brand();
}
double compute_min_travel_duration(const double& distance, const Vehicle& vehicle){
    return distance / vehicle.get_max_speed();
}
std::string compute_min_travel_duration_as_string(const double& distance, const Vehicle& vehicle){
    std::ostringstream oss;
    oss << std::setprecision(3) << std::fixed
        << compute_min_travel_duration(distance, vehicle) << " h";
    return oss.str();
}
std::vector<Vehicle*> filter_vehicles(
        std::vector<Vehicle*>::const_iterator vehicles_begin,
        std::vector<Vehicle*>::const_iterator vehicles_end,
        std::function<bool (const Vehicle&)> predicate){
    std::vector<Vehicle*> v;
    std::copy_if(vehicles_begin, vehicles_end,std::back_inserter(v),[&predicate](const Vehicle* a){return predicate(*a);});
    return v;
}
std::string to_string(std::vector<Vehicle*>::const_iterator vehicles_begin,
                      std::vector<Vehicle*>::const_iterator vehicles_end){
    std::ostringstream oss;
    for(auto i = vehicles_begin; i != vehicles_end; i++)
        oss<<to_string(**i)<<std::endl;
    return oss.str();
}
std::string to_string(Driver driver){
    std::stringstream oss;
    oss<<"<"<<driver.get_name()<<"> : [<"<<((driver.get_vehicle() != nullptr)?to_string(*driver.get_vehicle()):"no vehicle")<<">]";
    return oss.str();
}
void assign_vehicle_to_driver(std::vector<std::unique_ptr<Vehicle>>& vehicles, Driver& owner){
    if(vehicles.empty()) {
        owner.assign_vehicle(nullptr);
    }else{
        owner.assign_vehicle(std::move(vehicles.back()));
        vehicles.pop_back();
    }
}

Driver &Driver::operator=(Driver &&d) {
    name_ = std::move(d.name_);
    vehicle_ptr_ = std::move(d.vehicle_ptr_);
    return *this;
}
