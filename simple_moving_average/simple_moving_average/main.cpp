#include <iostream>
#include <random>
#include <chrono>
#include <limits>
#include "simple_moving_average.h"

int main()
{
	using namespace std::chrono;
	const size_t data_length = 1000000;
	float *f = new float[data_length];
	double *d = new double[data_length];
	std::default_random_engine engine(
		static_cast<unsigned int>(system_clock::to_time_t(system_clock::now())));
	std::uniform_real_distribution<> distr(std::numeric_limits<float>::min(),
										   std::numeric_limits<float>::max());
	for(size_t i = 0; i < data_length; ++i)
	{
		d[i] = distr(engine);
		f[i] = static_cast<float>(d[i]);
	}
	steady_clock::time_point start,
		end;
	duration<double> sec;
	double sec_count;

	// float
	simple_moving_average<float, 4> sma_f4;
	start = steady_clock::now();
	for(size_t i = 0; i < data_length; ++i) sma_f4.add_value(f[i]);
	end = steady_clock::now();
	sec = end - start;
	sec_count = sec.count();
	std::cout << "SMA<float, 4> - result " << sma_f4.get_ave() << ", speed ";
	if(sec_count) std::cout << static_cast<unsigned long>(data_length / sec.count());
	else std::cout << "infinity";
	std::cout << " values per second.\n";

	simple_moving_average<float, 8> sma_f8;
	start = steady_clock::now();
	for(size_t i = 0; i < data_length; ++i) sma_f8.add_value(f[i]);
	end = steady_clock::now();
	sec = end - start;
	sec_count = sec.count();
	std::cout << "SMA<float, 8> - result " << sma_f8.get_ave() << ", speed ";
	if(sec_count) std::cout << static_cast<unsigned long>(data_length / sec.count());
	else std::cout << "infinity";
	std::cout << " values per second.\n";

	simple_moving_average<float, 16> sma_f16;
	start = steady_clock::now();
	for(size_t i = 0; i < data_length; ++i) sma_f16.add_value(f[i]);
	end = steady_clock::now();
	sec = end - start;
	sec_count = sec.count();
	std::cout << "SMA<float, 16> - result " << sma_f16.get_ave() << ", speed ";
	if(sec_count) std::cout << static_cast<unsigned long>(data_length / sec.count());
	else std::cout << "infinity";
	std::cout << " values per second.\n";

	simple_moving_average<float, 32> sma_f32;
	start = steady_clock::now();
	for(size_t i = 0; i < data_length; ++i) sma_f32.add_value(f[i]);
	end = steady_clock::now();
	sec = end - start;
	sec_count = sec.count();
	std::cout << "SMA<float, 32> - result " << sma_f32.get_ave() << ", speed ";
	if(sec_count) std::cout << static_cast<unsigned long>(data_length / sec.count());
	else std::cout << "infinity";
	std::cout << " values per second.\n";

	simple_moving_average<float, 64> sma_f64;
	start = steady_clock::now();
	for(size_t i = 0; i < data_length; ++i) sma_f64.add_value(f[i]);
	end = steady_clock::now();
	sec = end - start;
	sec_count = sec.count();
	std::cout << "SMA<float, 64> - result " << sma_f64.get_ave() << ", speed ";
	if(sec_count) std::cout << static_cast<unsigned long>(data_length / sec.count());
	else std::cout << "infinity";
	std::cout << " values per second.\n";

	simple_moving_average<float, 128> sma_f128;
	start = steady_clock::now();
	for(size_t i = 0; i < data_length; ++i) sma_f128.add_value(f[i]);
	end = steady_clock::now();
	sec = end - start;
	sec_count = sec.count();
	std::cout << "SMA<float, 128> - result " << sma_f128.get_ave() << ", speed ";
	if(sec_count) std::cout << static_cast<unsigned long>(data_length / sec.count());
	else std::cout << "infinity";
	std::cout << " values per second.\n";

	// double
	simple_moving_average<double, 4> sma_d4;
	start = steady_clock::now();
	for(size_t i = 0; i < data_length; ++i) sma_d4.add_value(d[i]);
	end = steady_clock::now();
	sec = end - start;
	sec_count = sec.count();
	std::cout << "SMA<double, 4> - result " << sma_d4.get_ave() << ", speed ";
	if(sec_count) std::cout << static_cast<unsigned long>(data_length / sec.count());
	else std::cout << "infinity";
	std::cout << " values per second.\n";

	simple_moving_average<double, 8> sma_d8;
	start = steady_clock::now();
	for(size_t i = 0; i < data_length; ++i) sma_d8.add_value(d[i]);
	end = steady_clock::now();
	sec = end - start;
	sec_count = sec.count();
	std::cout << "SMA<double, 8> - result " << sma_d8.get_ave() << ", speed ";
	if(sec_count) std::cout << static_cast<unsigned long>(data_length / sec.count());
	else std::cout << "infinity";
	std::cout << " values per second.\n";

	simple_moving_average<double, 16> sma_d16;
	start = steady_clock::now();
	for(size_t i = 0; i < data_length; ++i) sma_d16.add_value(d[i]);
	end = steady_clock::now();
	sec = end - start;
	sec_count = sec.count();
	std::cout << "SMA<double, 16> - result " << sma_d16.get_ave() << ", speed ";
	if(sec_count) std::cout << static_cast<unsigned long>(data_length / sec.count());
	else std::cout << "infinity";
	std::cout << " values per second.\n";

	simple_moving_average<double, 32> sma_d32;
	start = steady_clock::now();
	for(size_t i = 0; i < data_length; ++i) sma_d32.add_value(d[i]);
	end = steady_clock::now();
	sec = end - start;
	sec_count = sec.count();
	std::cout << "SMA<double, 32> - result " << sma_d32.get_ave() << ", speed ";
	if(sec_count) std::cout << static_cast<unsigned long>(data_length / sec.count());
	else std::cout << "infinity";
	std::cout << " values per second.\n";

	simple_moving_average<double, 64> sma_d64;
	start = steady_clock::now();
	for(size_t i = 0; i < data_length; ++i) sma_d64.add_value(d[i]);
	end = steady_clock::now();
	sec = end - start;
	sec_count = sec.count();
	std::cout << "SMA<double, 64> - result " << sma_d64.get_ave() << ", speed ";
	if(sec_count) std::cout << static_cast<unsigned long>(data_length / sec.count());
	else std::cout << "infinity";
	std::cout << " values per second.\n";

	simple_moving_average<double, 128> sma_d128;
	start = steady_clock::now();
	for(size_t i = 0; i < data_length; ++i) sma_d128.add_value(d[i]);
	end = steady_clock::now();
	sec = end - start;
	sec_count = sec.count();
	std::cout << "SMA<double, 128> - result " << sma_d128.get_ave() << ", speed ";
	if(sec_count) std::cout << static_cast<unsigned long>(data_length / sec.count());
	else std::cout << "infinity";
	std::cout << " values per second.\n";

	delete[] d;
	delete[] f;
	return 0;
}
