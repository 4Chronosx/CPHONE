//prototype functions for the main utility function and global input validation
int utility(void);
void program_instructions(int n);
//prototype function for electricity bill calculator function and related subfunctions
int electricity_calculator(void);
float convert_to_kwh(float usage_per_day);
float calculate_device_consumption(float watts, float usage);
float calculate_total_bill(float device_consumption[], int index);
int end_loop(int choice);

//prototype for water bill calculator function and related subfunctions
int water_calculator(void);
