#include <iostream>
#include <string>
#include <curl/curl.h>

using namespace std;

class BaleApiCaller
{
private:
    string Token = "144208741:ERRaiwNRDXh6frCBxpMoexwjoqkpqi5Az8I";
    string BaseUrl = "https://tapi.bale.ai/";
    string AdminName = "";
    CURL* curl = nullptr;
    string GroupBaleId = "4594722835";

protected:
    void ChangeBaseUrl(string newUrl)
    {
        BaseUrl = newUrl;
    }

public:
    BaleApiCaller(string Name)
    {
        curl_global_init(CURL_GLOBAL_DEFAULT);
        curl = curl_easy_init();
        AdminName = Name;

        if (!curl)
        {
            cout << "curl init failed!" << endl;
        }

        cout << "admin name been saved!" << endl;
    }

    void SetAdminName(string newName)
    {
        AdminName = newName;
    }

    bool SendMessage()
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

    bool SendMessage(long chat_id, string message)
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

    bool SendMessage(string Picture)
    {
        string chat_id, message;

        cout << "Enter the chatId: ";
        cin >> chat_id;
        cin.ignore();

        cout << "Enter the Message: ";
        getline(cin, message);

        // فعلاً فقط پیام متنی می‌فرستد. برای عکس باید sendPhoto پیاده‌سازی شود.
        return SendMessage(stol(chat_id), message + "\nPicture: " + Picture);
    }

    bool GetProfileAddress()
    {
        string chat_id, username;

        cout << "Enter the chatId: ";
        cin >> chat_id;

        cout << "Enter the username: ";
        cin >> username;

        cout << "the link is: https://ble.ir/" << username << endl;
        return true;
    }

    bool SendMessageForMultipleUsers()
    {
        bool res = true;
        string message, chat_id_str;

        cin.ignore();
        cout << "Enter The Message: ";
        getline(cin, message);

        while (true)
        {
            cout << "Enter the Chat Id (for exit = n): ";
            cin >> chat_id_str;

            if (chat_id_str == "n" || chat_id_str == "N")
                break;

                long chat_id = stol(chat_id_str);
                res = SendMessage(chat_id, message);

                if (res == false)
                {
                    cout << "Failed To Send For CHAT ID: " << chat_id_str << endl;
                    break;
                }
        }

        cout << "Goodluck!" << endl;
        return res;
    }

    bool SendMessageForGroup(string GroupId)
    {
        bool res = true;

        if (GroupId == "")
            GroupId = this->GroupBaleId;

        string message;

        cin.ignore();
        cout << "Enter The Message: ";
        getline(cin, message);
        res = SendMessage(stol(GroupId), message);
        cout << "Invalid GroupId!" << endl;
        res = false;


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

    ~BaleApiCaller()
    {
        if (curl)
            curl_easy_cleanup(curl);

        curl_global_cleanup();
    }
};

void ShowMenu()
{
    cout
        << "1- Send Message With Chat Id"                   << endl
        << "2- Get User Profile Address"                    << endl
        << "3- Send Message For Group Of Users"             << endl
        << "4- Send Class Picture To User"                  << endl
        << "5- Send Message Inside Group"                   << endl
        << "6- Remove User From Group"                      << endl
        << "7- Monitor The Group Latest Messages"           << endl
        << "8- Add Group Users To Database"                 << endl
        << "9- Send Notification(message) For All Db Users" << endl
        << "0- Exit"                                        << endl;
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
            api_caller.SendMessage();
        else if (input == '2')
            api_caller.GetProfileAddress();
        else if (input == '3')
            api_caller.SendMessageForMultipleUsers();
        else if (input == '4')
        {
            string PictureId = "";
            cout << "Enter The Picture Id: ";
            cin >> PictureId;
            api_caller.SendMessage(PictureId);
        }
        else if (input == '5')
            api_caller.SendMessageForGroup("");
        else if (input == '6')
        {
            string GroupId, Username;
            long ChatId;

            cout << "Enter the group Id: ";
            cin >> GroupId;

            cout << "Enter the Username: ";
            cin >> Username;

            cout << "Enter the Chat Id: ";
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

    return 0;
}