#ifndef GET_UI_HEADER
#define GET_UI_HEADER

#include <vector>
#include <string>
/**
 * Get user input value
 */

 /**
  * Get integer between min_ui and max value
  */
int get_ui_int(int min_ui, int max_ui);

/*
 * ask user for values of a double vector
 */
std::vector<double> get_ui_vector_double(std::size_t n,
										 const std::string& name = "");

/*
 * ask user for values of a double matrix
 */
std::vector<std::vector<double> > get_ui_matrix(size_t max_n,
                                                const std::string& name = "");

 /**
  * ask user if he wants to continue
  */
bool get_ui_continue();

#endif //GET_UI_HEADER
