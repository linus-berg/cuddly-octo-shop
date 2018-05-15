#ifndef _EXECP_H
#define _EXECP_H
#include <string>
#include <exception>
namespace error {

class database_not_established : public std::exception {
  const char* what() const throw() {
    return "Database not established.";
  }
};

class database_item_not_found : public std::exception {
  private:
  const std::string ean_;
  public:
  const char* what() const throw() {
    return ean_.c_str();
  }
  database_item_not_found(std::string ean) : ean_(ean) {}
};

}
#endif
