#include <iostream>
#include <vector>
#include <string>
#include <any>
#include <sstream>
#include <map>

struct JsonObject {
  std::map<std::string, std::any> data;
};

template<typename T>
std::string toJson(const T& obj);

template<>
std::string toJson<JsonObject>(const JsonObject& obj);

template<>
std::string toJson<std::vector<JsonObject>>(const std::vector<JsonObject>& obj);

template<>
std::string toJson<std::vector<std::string>>(const std::vector<std::string>& obj);

template<>
std::string toJson<JsonObject>(const JsonObject& obj) {
  std::ostringstream oss;
  oss << "{";
  for (auto it = obj.data.begin(); it != obj.data.end(); ++it) {
    oss << "\"" << it->first << "\": ";
    if (it->second.type() == typeid(int)) {
      oss << std::any_cast<int>(it->second);
    } else if (it->second.type() == typeid(std::string)) {
      oss << "\"" << std::any_cast<std::string>(it->second) << "\"";
    } else if (it->second.type() == typeid(std::vector<JsonObject>)) {
      oss << toJson(std::any_cast<std::vector<JsonObject>>(it->second));
    } else if (it->second.type() == typeid(std::vector<std::string>)) {
      oss << toJson(std::any_cast<std::vector<std::string>>(it->second));
    }
    if (std::next(it) != obj.data.end()) {
      oss << ",";
    }
  }
  oss << "}";
  return oss.str();
}

template<>
std::string toJson<std::vector<JsonObject>>(const std::vector<JsonObject>& obj) {
  std::ostringstream oss;
  oss << "[";
  for (auto it = obj.begin(); it != obj.end(); ++it) {
    oss << toJson(*it);
    if (std::next(it) != obj.end()) {
      oss << ",";
    }
  }
  oss << "]";
  return oss.str();
}

template<>
std::string toJson<std::vector<std::string>>(const std::vector<std::string>& obj) {
  std::ostringstream oss;
  oss << "[";
  for (auto it = obj.begin(); it != obj.end(); ++it) {
    oss << "\"" << *it << "\"";
    if (std::next(it) != obj.end()) {
      oss << ",";
    }
  }
  oss << "]";
  return oss.str();
}

int main() {
  JsonObject alice;
  alice.data["name"] = std::string("alice");
  alice.data["profile"] = JsonObject{{{"land", std::string("Japan")}, {"age", 21}}};
  alice.data["friends"] = std::vector<std::string>{"bob", "jams"};

  std::string jsonStr = toJson(JsonObject{{{"users", std::vector<JsonObject>{alice}}}});

  std::cout << "JSON 形式の文字列: " << jsonStr << std::endl;

  return 0;
}
