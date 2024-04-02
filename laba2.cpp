#include <iostream>
#include <string>

class MeasurementDevice {
private:
	std::string* name;
	std::string* unit;
	int* minValue;
	int* maxValue;
	std::string* material;
	bool isDeviceActiveForMeasurement;

public:
	MeasurementDevice() : name(new std::string("")), unit(new std::string("")), minValue(new int(0)),
		maxValue(new int(0)), material(new std::string("")), isDeviceActiveForMeasurement(false) {
		std::cout << "Default constructor invoked. Memory allocated for MeasurementDevice.\n";
	}

	MeasurementDevice(const std::string& _name, const std::string& _unit, int _minValue,
		int _maxValue, const std::string& _material)
		: name(new std::string(_name)), unit(new std::string(_unit)), minValue(new int(_minValue)),
		maxValue(new int(_maxValue)), material(new std::string(_material)), isDeviceActiveForMeasurement(false) {
		std::cout << "Memory allocated for MeasurementDevice with parameters" << std::endl;
	}

	MeasurementDevice(const MeasurementDevice& other)
		: name(new std::string(*(other.name))), unit(new std::string(*(other.unit))),
		minValue(new int(*(other.minValue))), maxValue(new int(*(other.maxValue))),
		material(new std::string(*(other.material))), isDeviceActiveForMeasurement(false) {
		std::cout << "Memory allocated for MeasurementDevice copy" << std::endl;
	}

	~MeasurementDevice() {
		delete name;
		delete unit;
		delete minValue;
		delete maxValue;
		delete material;
		std::cout << "Memory deallocated for MeasurementDevice" << std::endl;
	}

	void startMeasuring() {
		if (!isDeviceActiveForMeasurement) {
			std::cout << "\nStart of measurement" << std::endl;
			isDeviceActiveForMeasurement = true;
		}
	}

	void stopMeasuring() {
		if (isDeviceActiveForMeasurement) {
			std::cout << "End of measurement\n" << std::endl;
			isDeviceActiveForMeasurement = false;
		}
	}

	void print() const {
		if (isDeviceActiveForMeasurement) {
			std::cout << "============" << std::endl;
			std::cout << "Name: " << *name << std::endl;
			std::cout << "Unit: " << *unit << std::endl;
			std::cout << "Min Value: " << *minValue << std::endl;
			std::cout << "Max Value: " << *maxValue << std::endl;
			std::cout << "Material: " << *material << std::endl;
			std::cout << "============" << std::endl;
		}
		else {
			std::cout << "You have not started the measurement\n" << std::endl;
		}

	}
};

int main() {
	MeasurementDevice thermometer("Thermometer", "Celsius", -50, 150, "Plastic");
	MeasurementDevice device2 = thermometer;
	MeasurementDevice device3;
	MeasurementDevice ruler("Ruler", "Centimeters", 0, 30, "Wood");

	thermometer.startMeasuring();
	thermometer.print();
	thermometer.stopMeasuring();

	ruler.startMeasuring();
	ruler.print();
	ruler.stopMeasuring();

	device2.print();
	device2.startMeasuring();
	device2.stopMeasuring();

	return 0;
}
