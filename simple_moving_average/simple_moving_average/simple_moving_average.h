#pragma once

template<typename T, size_t length> class simple_moving_average {
	size_t pos; // ������� � ������
	T buf[length]; // �����
	double ave; // �������� ����������� ��������
	bool buf_full; // ���������� �� � ������ �������� ��� ���������� ��������
public:
	simple_moving_average() : pos(0),
		ave(0.0),
		buf_full(false)
	{
		for(size_t i = 0; i < length; ++i) buf[i] = T();
	}

	/// <summary>
	/// ��������� �������� ������ �������� �� ����������� �������� � ��������� �����.
	/// </summary>
	/// <param name="value">����������� ��������</param>
	/// <param name="correct">���� ������� ���������, �� ����� �������� true ��� �����������
	/// ���������� �������� ��� ����������</param>
	/// <returns>�������� ����������� ��������</returns>
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
	/// ���������� �������� ����������� ��������.
	/// </summary>
	/// <param name="correct">���� ������� ���������, �� ����� �������� true ��� �����������
	/// ���������� �������� ��� ����������</param>
	/// <returns>�������� ����������� ��������</returns>
	double get_ave(bool *correct = nullptr)
	{
		if(correct) *correct = buf_full;
		return ave;
	}
};
