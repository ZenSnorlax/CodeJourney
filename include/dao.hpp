#include <string>

enum class UserStatus { Active, Inactive };

class UsersDao {
   public:
    static bool emailExists(const std::string &email);

    static void insert(const std::string &username, const std::string &password,
                       const std::string &email);

    static bool usernameExists(const std::string &username);

    static bool match(const std::string &username, const std::string &password);

    static void deleteuser(const std::string &username,
                           const std::string &password);

    static void updataStatus(const std::string &username, UserStatus status);

    static UserStatus getStatus(const std::string &username);

   private:
    static std::string db_name_;
    static std::string table_name_;

    static std::string statusToString(UserStatus status);
};

class ChatRoomsDao {
   public:
    static void insert(const std::string &room_name, int created_by);

    static bool roomExists(const std::string &room_name);

   private:
    static std::string db_name_;
    static std::string table_name_;
};

class UsersRoomRelationsDao {
   public:
    static void insert(int user_id, int room_id);

    static bool userRoomExists(int user_id, int room_id);

   private:
    static std::string db_name_;
    static std::string table_name_;
};
