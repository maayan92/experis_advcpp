#ifndef TEMPERATURE_SENSOR_HPP
#define TEMPERATURE_SENSOR_HPP

#include "iSensorAgent.hpp"
#include "device.hpp"
#include "event.hpp"

namespace smart_house {

class TemperatureSensor : public ISensorAgent {
public:
    TemperatureSensor(const Device& a_deviceDetails);
    TemperatureSensor();
    //virtual ~TemperatureSensor() = default;

    virtual void CreateEvent(const std::string& a_data, struct Event& a_event);

public:
    Device m_deviceDetails;
};

} // smart_house

#endif