#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>

class User {
 private:
  std::string name;
  std::string course;
  int nMec;
  std::vector<int> borrowed_books;

 public:
  User(std::string name, std::string course, int nMec)
      : name(std::move(name)), course(std::move(course)), nMec(nMec) {}

  void borrow_book(int book_id) {
    borrowed_books.push_back(book_id);
  }

  void return_book(int book_id) {
    borrowed_books.erase(std::remove(borrowed_books.begin(), borrowed_books.end(), book_id), borrowed_books.end());
  }

  bool can_borrow() const {
    return borrowed_books.size() < 3;
  }

  int get_nMec() const {
    return nMec;
  }

  std::string to_csv() const {
    std::ostringstream oss;
    oss << "student," << name << "," << nMec << "," << course;
    for (int book_id : borrowed_books) {
      oss << "," << book_id;
    }
    return oss.str();
  }

  static User from_csv(const std::string& csv_line) {
    std::istringstream iss(csv_line);
    std::string segment;
    std::vector<std::string> segments;

    while (std::getline(iss, segment, ',')) {
      segments.push_back(segment);
    }

    User user(segments[1], segments[3], std::stoi(segments[2]));
    for (size_t i = 4; i < segments.size(); ++i) {
      user.borrow_book(std::stoi(segments[i]));
    }

    return user;
  }

  friend std::ostream& operator<<(std::ostream& os, const User& user) {
    os << "Name: " << user.name << ", nMec: " << user.nMec << ", Course: " << user.course << ", Borrowed books: ";
    for (int book_id : user.borrowed_books) {
      os << book_id << " ";
    }
    return os;
  }
};

class Book {
 private:
  int id;
  std::string title;
  std::string type;
  bool available;

 public:
  Book(int id, std::string title, std::string type)
      : id(id), title(std::move(title)), type(std::move(type)), available(true) {}

  int get_id() const {
    return id;
  }

  bool is_available() const {
    return available;
  }

  void set_availability(bool available) {
    this->available = available;
  }

  std::string to_csv() const {
    std::ostringstream oss;
    oss << "book," << title << "," << id << "," << type;
    return oss.str();
  }

  static Book from_csv(const std::string& csv_line) {
    std::istringstream iss(csv_line);
    std::string segment;
    std::vector<std::string> segments;

    while (std::getline(iss, segment, ',')) {
      segments.push_back(segment);
    }

    return Book(std::stoi(segments[2]), segments[1], segments[3]);
  }

  friend std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << "ID: " << book.id << ", Title: " << book.title << ", Type: " << book.type << ", Available: " << (book.available ? "Yes" : "No");
    return os;
  }
};

class Library {
 private:
  std::vector<User> users;
  std::vector<Book> books;
  int next_book_id;

 public:
  Library() : next_book_id(100) {}

  void add_user(const User& user) {
    users.push_back(user);
  }

  void remove_user(int nMec) {
    users.erase(std::remove_if(users.begin(), users.end(), [nMec](const User& user) { return user.get_nMec() == nMec; }), users.end());
  }

  void print_users() const {
    for (const User& user : users) {
      std::cout << user << std::endl;
    }
  }

  void add_book(const std::string& title, const std::string& type) {
    books.push_back(Book(next_book_id++, title, type));
  }

  void print_books() const {
    for (const Book& book : books) {
      std::cout << book << std::endl;
    }
  }

  void loan(int nMec, int book_id) {
    auto user_it = std::find_if(users.begin(), users.end(), [nMec](const User& user) { return user.get_nMec() == nMec; });
    auto book_it = std::find_if(books.begin(), books.end(), [book_id](const Book& book) { return book.get_id() == book_id; });

    if (user_it == users.end() || book_it == books.end()) {
      std::cout << "User or book not found." << std::endl;
      return;
    }

    if (!user_it->can_borrow()) {
      std::cout << "User can't borrow more books." << std::endl;
      return;
    }

    if (!book_it->is_available()) {
      std::cout << "Book is not available." << std::endl;
      return;
    }

    if (book_it->is_available() && user_it->can_borrow()) {
      user_it->borrow_book(book_id);
      book_it->set_availability(false);
      std::cout << "Book loaned successfully." << std::endl;
    }
  }

  void return_book(int nMec, int book_id) {
    auto user_it = std::find_if(users.begin(), users.end(), [nMec](const User& user) { return user.get_nMec() == nMec; });
    auto book_it = std::find_if(books.begin(), books.end(), [book_id](const Book& book) { return book.get_id() == book_id; });

    if (user_it == users.end() || book_it == books.end()) {
      std::cout << "User or book not found." << std::endl;
      return;
    }

    user_it->return_book(book_id);
    book_it->set_availability(true);
    std::cout << "Book returned successfully." << std::endl;
  }

  void load_from_csv(const std::string& file_name) {
    std::ifstream infile(file_name);
    if (!infile.is_open()) {
      std::cout << "Error opening file." << std::endl;
      return;
    }

    std::string line;
    while (std::getline(infile, line)) {
      if (line.find("student") == 0) {
        users.push_back(User::from_csv(line));
      } else if (line.find("book") == 0) {
        books.push_back(Book::from_csv(line));
      }
    }

    infile.close();
    std::cout << "Library data loaded from file." << std::endl;
  }

  void save_to_csv(const std::string& file_name) const {
    std::ofstream outfile(file_name);
    if (!outfile.is_open()) {
      std::cout << "Error opening file." << std::endl;
      return;
    }

    for (const User& user : users) {
      outfile << user.to_csv() << std::endl;
    }

    for (const Book& book : books) {
      outfile << book.to_csv() << std::endl;
    }

    outfile.close();
    std::cout << "Library data saved to file." << std::endl;
  }
};

int main() {
  Library library;
  int option;

  while (true) {
    std::cout << "MENU OPTIONS:" << std::endl;
    std::cout << "1 - Enroll student" << std::endl;
    std::cout << "2 - Remove student" << std::endl;
    std::cout << "3 - Print list of users" << std::endl;
    std::cout << "4 - Register new book" << std::endl;
    std::cout << "5 - Print list of books" << std::endl;
    std::cout << "6 - Loan" << std::endl;
    std::cout << "7 - Return" << std::endl;
    std::cout << "8 - Load library's info from a CSV file" << std::endl;
    std::cout << "9 - Save current library's info to a CSV file" << std::endl;
    std::cout << "10 - Exit" << std::endl;

    std::cout << "Enter your choice: ";
    std::cin >> option;

    if (option == 1) {
      std::string name, course;
      int nMec;

      std::cout << "Enter name: ";
      std::cin.ignore();
      std::getline(std::cin, name);
      std::cout << "Enter course: ";
      std::getline(std::cin, course);
      std::cout << "Enter nMec: ";
      std::cin >> nMec;

      library.add_user(User(name, course, nMec));

    } else if (option == 2) {
      int nMec;

      std::cout << "Enter nMec: ";
      std::cin >> nMec;

      library.remove_user(nMec);

    } else if (option == 3) {
      library.print_users();

    } else if (option == 4) {
      std::string title, type;

      std::cout << "Enter title: ";
      std::cin.ignore();
      std::getline(std::cin, title);
      std::cout << "Enter type (CONDITIONAL or NORMAL): ";
      std::getline(std::cin, type);

      library.add_book(title, type);

    } else if (option == 5) {
      library.print_books();

    } else if (option == 6) {
      int nMec, book_id;

      std::cout << "Enter nMec: ";
      std::cin >> nMec;
      std::cout << "Enter book ID: ";
      std::cin >> book_id;

      library.loan(nMec, book_id);

    } else if (option == 7) {
      int nMec, book_id;

      std::cout << "Enter nMec: ";
      std::cin >> nMec;
      std::cout << "Enter book ID: ";
      std::cin >> book_id;

      library.return_book(nMec, book_id);

    } else if (option == 8) {
      std::string file_name;

      std::cout << "Enter file name: ";
      std::cin.ignore();
      std::getline(std::cin, file_name);

      library.load_from_csv(file_name);

    } else if (option == 9) {
      std::string file_name;

      std::cout << "Enter file name: ";
      std::cin.ignore();
      std::getline(std::cin, file_name);

      library.save_to_csv(file_name);

    } else if (option == 10) {
      break;
    }
  }

  return 0;
}