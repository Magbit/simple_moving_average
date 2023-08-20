#pragma once

template<typename T, size_t length> class simple_moving_average {
	size_t pos; // ѕозици€ в буфере
	T buf[length]; // Ѕуфер
	double ave; // «начение скольз€щего среднего
	bool buf_full; // ƒостаточно ли в буфере значений дл€ вычислени€ среднего
public:
	simple_moving_average() : pos(0),
		ave(0.0),
		buf_full(false)
	{
		for(size_t i = 0; i < length; ++i) buf[i] = T();
	}

	/// <summary>
	/// ¬ытесн€ет наиболее старое значение из скольз€щего среднего и добавл€ет новое.
	/// </summary>
	/// <param name="value">ƒобавл€емое значение</param>
	/// <param name="correct">≈сли передан указатель, то будет запасино true при достаточном
	/// количестве значений дл€ усреднени€</param>
	/// <returns>«начение скольз€щего среднего</returns>
	double add_value(const T &value, bool *correct = nullptr)
	{
		ave = ave - buf[pos] / static_cast<double>(length) + value / static_cast<double>(length);
		buf_full |= pos == (length - 1);
		if(correct) *correct = buf_full;
		buf[pos] = value;
		pos = (pos + 1) % length;
		return ave;
	}
	/// <summary>
	/// ¬озвращает значение скольз€щего среднего.
	/// </summary>
	/// <param name="correct">≈сли передан указатель, то будет запасино true при достаточном
	/// количестве значений дл€ усреднени€</param>
	/// <returns>«начение скольз€щего среднего</returns>
	double get_ave(bool *correct = nullptr)
	{
		if(correct) *correct = buf_full;
		return ave;
	}
};
