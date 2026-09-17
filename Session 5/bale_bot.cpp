#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

class BaleApiCaller
{
    private:
        string Token = "144208741:ERRaiwNRDXh6frCBxpMoexwjoqkpqi5Az8I";
        string BaseUrl = "https://tapi.bale.ai/";
        string AdminName = "";
        CURL* curl = curl_easy_init();
        string GroupBaleId = "4594722835";
        string DeveloperId = "969231957";
        string GroupPhoto = "1807033026:6642125903208718081:1:1f53fb33008f0f25bbef6dd7a1e4ee1c";

    protected:
        void ChangeBaseUrl(string newUrl)
        {
            BaseUrl = newUrl;
        }

    public:
        BaleApiCaller(string Name)
        {
            AdminName = Name;

            curl_global_init(CURL_GLOBAL_DEFAULT);
            curl = curl_easy_init();

            if (!curl)
            {
                cout << "curl init failed!" << endl;
            }

            cout << "admin name been saved!" << endl;
        }

        bool Log(string message)
        {
            message += "\n\nSent From " + AdminName;

            char* encodedMessage =
                curl_easy_escape(curl, message.c_str(), 0);

            if (!encodedMessage)
                return false;

            string url =
                BaseUrl +
                "bot" + Token +
                "/sendMessage?chat_id=" +
                this->DeveloperId +
                "&text=" +
                encodedMessage;

            curl_free(encodedMessage);

            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

            CURLcode result = curl_easy_perform(curl);

            return result == CURLE_OK;
        }

        // کپسوله سازی
        void SetAdminName(string newName)   // setter
        {
            AdminName = newName;
        }
        string GetAdminName()   // getter
        {
            return AdminName;
        }

        bool SendBaleMessage()
        {
            string chat_id, message;
            
            cout << "Enter the chatId: ";
            cin >> chat_id;

            cin.ignore();
            cout << "Enter the Message: ";
            getline(cin, message);
            
            message += "\n\nSent From " + AdminName;

            char* encodedMessage =
                curl_easy_escape(curl, message.c_str(), 0);

            if (!encodedMessage)
                return false;

            string url =
                BaseUrl +
                "bot" + Token +
                "/sendMessage?chat_id=" +
                chat_id +
                "&text=" +
                encodedMessage;

            curl_free(encodedMessage);

            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

            CURLcode result = curl_easy_perform(curl);

            return result == CURLE_OK;
        }
        bool SendBaleMessage(long chat_id, string message)
        {
            message += "\n\nSent From " + AdminName;

            char* encodedMessage =
                curl_easy_escape(curl, message.c_str(), 0);

            if (!encodedMessage)
                return false;

            string url =
                BaseUrl +
                "bot" + Token +
                "/sendMessage?chat_id=" +
                to_string(chat_id) +
                "&text=" +
                encodedMessage;

            curl_free(encodedMessage);

            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

            CURLcode result = curl_easy_perform(curl);

            return result == CURLE_OK;
        }

        static size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* output)
        {
            size_t totalSize = size * nmemb;
            output->append((char*)contents, totalSize);
            return totalSize;
        }

    bool GetProfileAddress()
    {
        string chat_id;
        string response_data;

        cout << "Enter the chatId: ";
        cin >> chat_id;

        string url = BaseUrl + "bot" + Token + "/getChat?chat_id=" + chat_id;

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_data);

        CURLcode res = curl_easy_perform(curl);

        if (res != CURLE_OK)
        {
            cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
            return false;
        }

        json j;
        try
        {
            j = json::parse(response_data);
        }
        catch (const json::parse_error& e)
        {
            cerr << "JSON parse error: " << e.what() << endl;
            return false;
        }

        if (!j.contains("ok") || j["ok"] != true)
        {
            cout << "API Error" << endl;
            return false;
        }

        string result = "user data:\n";

        string username = "";
        if (j["result"].contains("username") && !j["result"]["username"].is_null())
        {
            username = j["result"]["username"].get<string>();
            result += "usernameL: " + username + "\n";
        }

        if (j["result"].contains("first_name") && !j["result"]["first_name"].is_null())
        {
            result += "firstname: " + j["result"]["first_name"].get<string>() + "\n";
        }

        if (j["result"].contains("last_name") && !j["result"]["last_name"].is_null())
        {
            result += "lastname: " + j["result"]["last_name"].get<string>() + "\n";
        }



        result += "type:" + j["result"]["type"].get<string>() + "\n";

        if (username.empty())
            result += "the link is: https://ble.ir/" + chat_id;
        else
            result += "the link is: https://ble.ir/" + username;

        cout << result << endl;

        return true;
    }

    bool SendMessageForMultipleUsers()
        {
            bool res = true;
            string message, chat_id;

            cout << "Enter The Message: ";
            getline(cin, message);

            while(true)
            {
                cout << "Enter the Chat Id (for exist = n): ";
                cin >> chat_id;

                if (chat_id == "n" || chat_id == "N")
                    break;

                res = SendBaleMessage(stol(chat_id), message);

                if (res == false)
                {
                    cout << "Failed To Send For CHAT ID: " << chat_id << endl;
                    break;
                }
            }

            cout << "Goodluck!" << endl;
            return res;
        }

        bool RemoveUserFromGroup(string GroupId, string Username, long UserChatId)
        {
            bool res = true;
            if (GroupId == "")
                GroupId = this->GroupBaleId;

            if (Username != "")
            {
                // implementation
            }
            else if (UserChatId > 0)
            {
                // implementation
            }
            else
            {
                cout << "Invalid Input!";
                res = false;
            }

            return res;
        }
        void ShowLatestGroupMessages()
        {

        }
        bool AddGroupUsersToDb(string GroupId)
        {
            if (GroupId == "")
                GroupId = this->GroupBaleId;

            // implementation

            return true;
        }
        bool SendNotification(string message)
        {
            // implementation

            return true;
        }
        bool SendClassPhoto()
        {
            string chat_id, message;
            
            cout << "Enter the chatId: ";
            cin >> chat_id;

            cout << "Enter the Message: ";
            cin >> message;

            message += "\n\nSent From " + AdminName;

            char* encodedMessage =
                curl_easy_escape(curl, message.c_str(), 0);

            if (!encodedMessage)
                return false;

            string url =
                BaseUrl +
                "bot" + Token +
                "/sendPhoto?chat_id=" +
                chat_id +
                "&photo=" +
                GroupPhoto +
                "&caption=" +
                encodedMessage;

            curl_free(encodedMessage);

            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

            CURLcode result = curl_easy_perform(curl);

            return result == CURLE_OK;
        }

        ~BaleApiCaller()
        {
            if (curl)
                curl_easy_cleanup(curl);

            curl_global_cleanup();
        }
};

void ShowMenu()
{
    cout << endl << endl
    << "1- Send Message With Chat Id"                              << endl
    << "2- Get User Profile Address"                               << endl
    << "3- Send Message For Group Of Users"                        << endl
    << "4- Send Class Picture To User"                             << endl
    << "5- Send Message Inside Group"                              << endl
    << "6- Remove User From Group"                                 << endl
    << "7- Monitor The Group Latest Messages"                      << endl
    << "8- Add Group Users To Database"                            << endl
    << "9- Send Notification(message) For All Db Users"            << endl
    << "0- Exit"                                                   << endl;
}

int main()
{
    string Name;
    cout << "Enter Name Of The Admin of Bot: ";
    cin >> Name;


    BaleApiCaller api_caller(Name);


    char input = 'a';

    while (input != '0')
    {
        ShowMenu();

        cout << "Choose: ";
        cin >> input;

        if (input == '1')
            api_caller.SendBaleMessage();
        else if (input == '2')
            api_caller.GetProfileAddress();
        else if (input == '3')
            api_caller.SendMessageForMultipleUsers();
        else if (input == '4')
        {
            api_caller.SendClassPhoto();
        }
        else if (input == '5')
            api_caller.SendBaleMessage();
        else if (input == '6')
        {
            string GroupId, Username;
            long ChatId;

            cout << "Enter the group Id: ";
            cin >> GroupId;

            cout << "Etner the Username: ";
            cin >> Username;

            cout << "Etner the Chat Id";
            cin >> ChatId;

            api_caller.RemoveUserFromGroup(GroupId, Username, ChatId);
        }
        else if (input == '7')
            api_caller.ShowLatestGroupMessages();
        else if (input == '8')
            api_caller.AddGroupUsersToDb("");
        else if (input == '9')
        {
            string message = "";
            cout << "Enter the notification Message: ";
            cin >> message;

            api_caller.SendNotification(message);
        }
        else if (input == '0')
            break;
        else
        {
            cout << "Invalid Input! try again!" << endl;
            continue;
        }
    }
}