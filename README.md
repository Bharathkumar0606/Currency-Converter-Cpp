# 💱 Real-Time Currency Converter (C++)

![C++](https://img.shields.io/badge/Language-C++-blue)
![API](https://img.shields.io/badge/API-ExchangeRate--API-green)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

---

## 📌 Overview
A real-time currency converter built using C++ that fetches live exchange rates via API and supports multiple currency conversions with robust error handling and fallback mechanisms.

---

## ✨ Key Features
- 🌐 Real-time exchange rates using REST API  
- 🔁 Multi-currency support (USD, INR, EUR, GBP)  
- 🧠 Input validation for safe user interaction  
- ⚠️ API error handling  
- 📉 Offline fallback rates when API fails  
- 🔄 Loop-based continuous conversion  

---

## 🛠️ Tech Stack
- **Language:** C++  
- **Libraries:** nlohmann/json  
- **Tools:** cURL  
- **Concepts:** API Integration, File Handling, Error Handling  

---

## 🧩 How It Works
1. User selects source and target currency  
2. Program calls API to fetch latest exchange rates  
3. Parses JSON response  
4. Performs conversion  
5. Displays result instantly  

---

## ▶️ How to Run

```bash
g++ currency.cpp -o currency
./currency