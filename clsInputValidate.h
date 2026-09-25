#pragma once
#include <iostream>
#include <string>
#include <limits> // For numeric_limits

using namespace std;

class clsInputValidate {
public:
    // Check if number is in range
    template <typename T>
    static bool IsNumberBetween(T Number, T From, T To) {
        return (Number >= From && Number <= To);
    }

    // Check if date is in range
    static bool IsDateBetween(clsDate Date, clsDate From, clsDate To) {
        // Range: From -> To
        if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)) &&
            (clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))) {
            return true;
        }

        // Range: To -> From
        if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)) &&
            (clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))) {
            return true;
        }
        return false;
    }

    // Get any valid number from user
    template <typename T>
    static T ReadNumber(string ErrorMessage = "Invalid Number, Enter again\n") {
        T Number;
        while (!(cin >> Number)) {
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            cout << ErrorMessage;
        }
        return Number;
    }

    // Get a valid number within a specific range
    template <typename T>
    static T ReadNumberBetween(T From, T To, string ErrorMessage = "Number is not within range, Enter again:\n") {
        T Number = ReadNumber<T>();
        while (!IsNumberBetween(Number, From, To)) {
            cout << ErrorMessage;
            Number = ReadNumber<T>();
        }
        return Number;
    }

    /* -------------------------------------------------------------
       Old functions kept for backward compatibility (Don't break other classes)
       ------------------------------------------------------------- */

    static short ReadShortNumber(string ErrorMessage = "Invalid Number, Enter again\n") {
        return ReadNumber<short>(ErrorMessage);
    }

    static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again\n") {
        return ReadNumber<int>(ErrorMessage);
    }

    static double ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again\n") {
        return ReadNumber<float>(ErrorMessage);
    }

    static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again\n") {
        return ReadNumber<double>(ErrorMessage);
    }

    static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not within range, Enter again:\n") {
        return ReadNumberBetween<short>(From, To, ErrorMessage);
    }

    static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n") {
        return ReadNumberBetween<int>(From, To, ErrorMessage);
    }

    static double ReadFloatNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n") {
        return ReadNumberBetween<float>(From, To, ErrorMessage);
    }

    static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n") {
        return ReadNumberBetween<double>(From, To, ErrorMessage);
    }

    // Check if date is valid
    static bool IsValideDate(clsDate Date) {
        return clsDate::IsValidDate(Date);
    }

    // Get a full line of text from user
    static string ReadString() {
        string S1 = "";
        getline(cin >> ws, S1); // ws skips initial spaces/newlines
        return S1;
    }
};
