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
        CURL* curl = curl_easy_init();

    protected:
        void ChangeBaseUrl(string newUrl)
        {
            BaseUrl = newUrl;
        }

    public:
        // تابع سازنده
        BaleApiCaller(string Name)
        {
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

        bool SendMessage(long chat_id, string message)
        {
            bool response = false;
            message = message + "\n\nSent From " + AdminName;
            string url = BaseUrl + "bot" + Token + "/sendMessage?chat_id=" + to_string(chat_id) + "&text=" + message;
            curl_easy_escape(curl, message.c_str(), message.length());
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            CURLcode result = curl_easy_perform(curl);
            if (result == CURLE_OK)
                response = true;
            curl_free(url.c_str());
            return response;
        }

        ~BaleApiCaller()
        {
            curl_easy_cleanup(curl);
        }
};

int main()
{
    BaleApiCaller mohsenBot("mohsen shahani");

    bool res = mohsenBot.SendMessage(969231957, "سلام");
    // mohsenBot.Token = "1231435";

    if (res)
    {
        cout << "Message Have Been Sent Successfully.";
    }
    else
    {
        cout << "UnSuccessful.";
    }

    cout << mohsenBot.GetAdminName() << endl;
    return 0;
}