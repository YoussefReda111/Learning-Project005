#include <iostream>
#include <vector>
#include <string>

using namespace std;

class cls_calculator
{
private:
	enum en_operations
	{
		adding, clearing, dividing, multiplying, subtracting
	};
	en_operations _operation_type = clearing;
	float _calculated_number = 0, _result;
	int _number_in_operation;
	vector <float> _vec_all_results;

public:
	void add(float added_number)
	{
		_result = _calculated_number + added_number;
		_vec_all_results.push_back(_result);
		_calculated_number = _result;
		_number_in_operation = added_number;
		_operation_type = adding;
	}

	void subtract(float subtracted_number)
	{
		_result = _calculated_number - subtracted_number;
		_vec_all_results.push_back(_result);
		_calculated_number = _result;
		_number_in_operation = subtracted_number;
		_operation_type = subtracting;
	}

	void divide(float divided_by_number)
	{
		_result = _calculated_number / divided_by_number;
		_vec_all_results.push_back(_result);
		_calculated_number = _result;
		_number_in_operation = divided_by_number;
		_operation_type = dividing;
	}

	void multiply(float multiplyed_by_number)
	{
		_result = _calculated_number * multiplyed_by_number;
		_vec_all_results.push_back(_result);
		_calculated_number = _result;
		_number_in_operation = multiplyed_by_number;
		_operation_type = multiplying;
	}

	void clear()
	{
		_result = _calculated_number = _number_in_operation = 0;
		_operation_type = clearing;
		_vec_all_results.clear();
	}

	string get_final_results()
	{
		if (_vec_all_results.empty())
			return "There is no recorded results.";
		else
		{
			string str_all_results = "All recorded results are: ";
			float last_result = _vec_all_results.back();
			for (float result : _vec_all_results)
			{
				str_all_results += to_string(result);
				if (result != last_result)
					str_all_results += ", ";
			}
			return str_all_results;
		}
	}

	void print_result()
	{
		string str_result = "Result after ";
		switch (_operation_type)
		{
		case adding: str_result += "adding " + to_string(_number_in_operation); break;
		case subtracting: str_result += "subtracting " + to_string(_number_in_operation); break;
		case dividing: str_result += "dividing by " + to_string(_number_in_operation); break;
		case multiplying: str_result += "multiplying by " + to_string(_number_in_operation); break;
		case clearing: str_result += "clearing";
		}
		str_result += " is: " + to_string(_result);
		cout << str_result << endl;
	}
};

int main()
{

}