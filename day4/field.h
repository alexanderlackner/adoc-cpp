#ifndef field_H
#define field_H

class field
{
  	int *numbers;
  	int *marked;
  	int hits;
	bool has_won;

public:
  	field();
	~field();
	void add_line_to_field(int y_coordinate, int a, int b, int c, int d, int e);
  	void mark(int target);
	bool check_for_completion();
	int sum_of_all_unmarked_numbers();
	void print_field();
	void print_marked();
	void toggle_has_won();
	bool get_has_won();
};

#endif