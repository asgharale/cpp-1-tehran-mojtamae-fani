#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <curl/curl.h>

using namespace std;

// Called by curl to append received bytes into a std::string.
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    size_t totalSize = size * nmemb;
    ((string*)userp)->append((char*)contents, totalSize);
    return totalSize;
}

class BaleApiCaller
{
    private:
        string Token = "144208741:ERRaiwNRDXh6frCBxpMoexwjoqkpqi5Az8I";
        string BaseUrl = "https://tapi.bale.ai/";
        string AdminName = "";
        CURL* curl = curl_easy_init();
        string GroupBaleId = "4594722835";
        string DbFilePath = "bale_users_db.txt";

    protected:
        void ChangeBaseUrl(string newUrl)
        {
            BaseUrl = newUrl;
        }

        // Generic GET request against the bot API, returns raw response body.
        string HttpGet(string endpointWithParams)
        {
            string response;
            string url = BaseUrl + "bot" + Token + "/" + endpointWithParams;

            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

            CURLcode result = curl_easy_perform(curl);

            if (result != CURLE_OK)
                cout << "curl request failed: " << curl_easy_strerror(result) << endl;

            return response;
        }

        // Very small helper to grab the value after a given "key":"..." or "key":123
        // in a JSON-looking string. Not a real JSON parser - fine for simple scraping.
        vector<string> ExtractField(const string& json, const string& key)
        {
            vector<string> results;
            string pattern = "\"" + key + "\":";
            size_t pos = 0;

            while ((pos = json.find(pattern, pos)) != string::npos)
            {
                pos += pattern.length();

                if (pos >= json.size())
                    break;

                string value;

                if (json[pos] == '"')
                {
                    // string field
                    size_t end = json.find('"', pos + 1);
                    if (end == string::npos)
                        break;
                    value = json.substr(pos + 1, end - pos - 1);
                    pos = end + 1;
                }
                else
                {
                    // numeric / literal field
                    size_t end = json.find_first_of(",}", pos);
                    if (end == string::npos)
                        break;
                    value = json.substr(pos, end - pos);
                    pos = end;
                }

                results.push_back(value);
            }

            return results;
        }

    public:
        // تابع سازنده
        BaleApiCaller(string Name)
        {
            curl_global_init(CURL_GLOBAL_DEFAULT);
            curl = curl_easy_init();

            if (!curl)
            {
                cout << "curl init failed!" << endl;
            }

            AdminName = Name;
            cout << "admin name been saved!" << endl;
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

        // Sends a photo the bot already has a file_id for (e.g. uploaded earlier,
        // or forwarded to the bot). This does NOT upload a local file from disk -
        // that would need a multipart/form-data POST instead of a query string.
        bool SendBaleMessage(string Picture)
        {
            string chat_id, message;

            cout << "Enter the chatId: ";
            cin >> chat_id;

            cout << "Enter the Message (caption, optional): ";
            cin >> message;

            char* encodedCaption = curl_easy_escape(curl, message.c_str(), 0);
            char* encodedPhoto = curl_easy_escape(curl, Picture.c_str(), 0);

            if (!encodedCaption || !encodedPhoto)
            {
                if (encodedCaption) curl_free(encodedCaption);
                if (encodedPhoto) curl_free(encodedPhoto);
                return false;
            }

            string url =
                BaseUrl +
                "bot" + Token +
                "/sendPhoto?chat_id=" +
                chat_id +
                "&photo=" +
                encodedPhoto +
                "&caption=" +
                encodedCaption;

            curl_free(encodedCaption);
            curl_free(encodedPhoto);

            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

            CURLcode result = curl_easy_perform(curl);

            if (result != CURLE_OK)
                cout << "Failed to send photo: " << curl_easy_strerror(result) << endl;

            return result == CURLE_OK;
        }
        bool GetProfileAddress()
        {
            string chat_id, username;

            cout << "Enter the chatId: ";
            cin >> chat_id;


            cout << "the link is: httpshttps://ble.ir/" + username << endl;
            return true;
        }
        bool SendMessageForMultipleUsers()
        {
            bool res = true;
            string message, chat_id;

            cout << "Enter The Message: ";
            cin >> message;

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

        // Sends a message inside the group (default GroupBaleId if none given).
        // A group chat_id is just another chat_id as far as sendMessage cares.
        bool SendMessageForGroup(string GroupId)
        {
            if (GroupId == "")
                GroupId = this->GroupBaleId;

            string message;
            cout << "Enter The Message: ";
            cin >> message;

            message += "\n\nSent From " + AdminName;

            char* encodedMessage = curl_easy_escape(curl, message.c_str(), 0);
            if (!encodedMessage)
                return false;

            string url =
                BaseUrl +
                "bot" + Token +
                "/sendMessage?chat_id=" +
                GroupId +
                "&text=" +
                encodedMessage;

            curl_free(encodedMessage);

            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

            CURLcode result = curl_easy_perform(curl);

            if (result != CURLE_OK)
                cout << "Failed to send group message: " << curl_easy_strerror(result) << endl;

            return result == CURLE_OK;
        }

        // Removes/bans a user from the group. Note: the Bale API (like the
        // Telegram API it mirrors) can only ban by numeric user_id - there is
        // no endpoint to resolve a @username to an id, so that path can't
        // actually be completed here.
        bool RemoveUserFromGroup(string GroupId, string Username, long UserChatId)
        {
            bool res = true;
            if (GroupId == "")
                GroupId = this->GroupBaleId;

            if (UserChatId > 0)
            {
                string endpoint =
                    "banChatMember?chat_id=" + GroupId +
                    "&user_id=" + to_string(UserChatId);

                string response = HttpGet(endpoint);

                if (response.find("\"ok\":true") == string::npos)
                {
                    cout << "Failed to remove user. Response: " << response << endl;
                    res = false;
                }
                else
                {
                    cout << "User removed successfully." << endl;
                }
            }
            else if (Username != "")
            {
                cout << "Bale's API only supports removing users by numeric user_id, "
                     << "not by username. Please provide the user's chat/user id instead."
                     << endl;
                res = false;
            }
            else
            {
                cout << "Invalid Input!" << endl;
                res = false;
            }

            return res;
        }

        // Fetches recent updates and prints any text messages that belong to
        // the group chat.
        void ShowLatestGroupMessages()
        {
            string response = HttpGet("getUpdates?limit=20");

            vector<string> texts = ExtractField(response, "text");

            if (texts.empty())
            {
                cout << "No recent messages found." << endl;
                return;
            }

            cout << "--- Latest messages ---" << endl;
            for (const string& t : texts)
                cout << "> " << t << endl;
            cout << "-----------------------" << endl;
        }

        // Bale bots can't list all group members - only admins, via
        // getChatAdministrators. This pulls those admin ids and appends any
        // new ones to a local text file used as our "db".
        bool AddGroupUsersToDb(string GroupId)
        {
            if (GroupId == "")
                GroupId = this->GroupBaleId;

            string response = HttpGet("getChatAdministrators?chat_id=" + GroupId);
            vector<string> ids = ExtractField(response, "id");

            if (ids.empty())
            {
                cout << "No users found (or request failed). Response: " << response << endl;
                return false;
            }

            // Load existing ids so we don't duplicate entries.
            vector<string> existing;
            ifstream inFile(DbFilePath);
            string line;
            while (getline(inFile, line))
                existing.push_back(line);
            inFile.close();

            ofstream outFile(DbFilePath, ios::app);
            int added = 0;

            for (const string& id : ids)
            {
                bool alreadyThere = false;
                for (const string& e : existing)
                {
                    if (e == id)
                    {
                        alreadyThere = true;
                        break;
                    }
                }

                if (!alreadyThere)
                {
                    outFile << id << endl;
                    added++;
                }
            }

            outFile.close();
            cout << added << " new user(s) added to db (" << DbFilePath << ")." << endl;

            return true;
        }

        // Sends the same message to every chat id stored in the local db file.
        bool SendNotification(string message)
        {
            ifstream inFile(DbFilePath);

            if (!inFile.is_open())
            {
                cout << "No db file found yet. Run option 8 first to populate it." << endl;
                return false;
            }

            string line;
            bool allOk = true;
            int count = 0;

            while (getline(inFile, line))
            {
                if (line.empty())
                    continue;

                try
                {
                    long id = stol(line);
                    bool ok = SendBaleMessage(id, message);

                    if (!ok)
                    {
                        cout << "Failed to notify user: " << line << endl;
                        allOk = false;
                    }
                    else
                    {
                        count++;
                    }
                }
                catch (const std::invalid_argument&)
                {
                    cout << "Skipping invalid db entry: " << line << endl;
                }
            }

            inFile.close();
            cout << "Notified " << count << " user(s)." << endl;

            return allOk;
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
            string PictureId = "";
            cout << "Enter The Picture Id: ";
            cin >> PictureId;
            api_caller.SendBaleMessage(PictureId);
        }
        else if (input == '5')
            api_caller.SendMessageForGroup("");
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