# 💱 Real-Time Currency Converter (C++)

## 📌 Overview
This is a real-time currency converter built using C++ that fetches live exchange rates from an API and converts between multiple currencies.

## 🚀 Features
- 🌐 Real-time exchange rates using API
- 🔁 Supports multiple currencies (USD, INR, EUR, GBP)
- 🧠 Input validation
- ⚠️ Error handling for API failures
- 📉 Offline fallback rates
- 🔄 Continuous conversion (loop-based)

## 🛠️ Technologies Used
- C++
- JSON (nlohmann/json)
- cURL
- REST API

## ▶️ How to Run
```bash
g++ currency.cpp -o currency
./currency