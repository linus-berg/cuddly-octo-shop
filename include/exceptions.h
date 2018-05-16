/** 
* @file exceptions.h 
* @brief Contains all exceptions. 
* @author Linus Gunnarsson
* @date 16/05/2018
*/
#ifndef _EXECP_H
#define _EXECP_H
#include <string>
#include <exception>
namespace error {
/**
 *  This exception is incase no database 'connection' can be established.
 */
class database_not_established : public std::exception {
  const char* what() const throw() {
    return "ERROR: Database not established. (file not found or corrupted)";
  }
};
/**
 *  This exception is incase an item can not be found in the database.
 */
class database_item_not_found : public std::exception {
  private:
  std::string info_ = "EXCEPTION WARNING item_not_found: ";
  public:
  const char* what() const throw() {
    return info_.c_str();
  }
  database_item_not_found(std::string ean) {
    info_ += ean;
  }
};

}
#endif
