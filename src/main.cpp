// Updated Wi-Fi repeater function
// DNS black/white list support
// WebUI modifications

#include <iostream>
#include <string>
#include <vector>

class WiFiRepeater {
public:
    void setDNS(const std::string& dns) {
        if (dns.empty()) {
            dns_ = "114.114.114.114"; // Maintain default DNS
        } else {
            dns_ = dns;
        }
    }

    void addToWhitelist(const std::string& domain) {
        whitelist_.push_back(domain);
    }

    void addToBlacklist(const std::string& domain) {
        blacklist_.push_back(domain);
    }

    void displaySettings() {
        std::cout << "Current DNS: " << dns_ << std::endl;
        std::cout << "Whitelisted domains: " << std::endl;
        for (const auto& domain : whitelist_) {
            std::cout << "- " << domain << std::endl;
        }
        std::cout << "Blacklisted domains: " << std::endl;
        for (const auto& domain : blacklist_) {
            std::cout << "- " << domain << std::endl;
        }
    }

private:
    std::string dns_;
    std::vector<std::string> whitelist_;
    std::vector<std::string> blacklist_;
};

int main() {
    WiFiRepeater repeater;
    repeater.setDNS(""); // Set to default
    repeater.addToWhitelist("example.com");
    repeater.addToBlacklist("malicious.com");
    repeater.displaySettings();
    return 0;
}