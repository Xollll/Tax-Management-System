#include <iostream>
using namespace std;

// Function to calculate income tax based on taxable income
double calculateIncomeTax(double taxableIncome) {
    double incomeTax;

    if (taxableIncome < 20000.00)
        incomeTax = taxableIncome * 0.07;
    else if (taxableIncome >= 20000.00 && taxableIncome < 35000.00)
        incomeTax = taxableIncome * 0.08;
    else if (taxableIncome >= 35000.00 && taxableIncome < 75000.00)
        incomeTax = taxableIncome * 0.10;
    else if (taxableIncome >= 75000.00 && taxableIncome < 120000.00)
        incomeTax = taxableIncome * 0.15;
    else
        incomeTax = taxableIncome * 0.25;

    return incomeTax;
}

// Function to calculate total income tax for all employees
double calculateTotalIncomeTax(double *incomeTaxArray, int numEmployees) {
    double totalIncomeTax = 0.00;

    for (int i = 0; i < numEmployees; i++) {
        totalIncomeTax += incomeTaxArray[i];
    }

    return totalIncomeTax;
}

int main() {
    const int numEmployees = 1;
    double ownSelfRebate = 5000.00;
    double wifeRebate = 3000.00;
    double childRebate = 1000.00;
    int maxChildLimit = 5;

    double taxableIncome;
    double incomeTaxArray[numEmployees];
    

    // Collect information for each employee
    for (int i = 0; i < numEmployees; i++) {
        string status;
        int numChildren;
        double totalRebate = 0.00;
        double zakatPaid;
        string gender;
        string religion;
       string employeeName;
       
       
        cout << "ABC COMPANY" << endl;

        cout << "Employee " << i + 1 << " Information:" << endl;
        cout << "------------------------" << endl;
        
        cout << "Name : ";
        cin >> employeeName;

        cout << "Gender (M - Male, F - Female): ";
        cin >> gender;

        cout << "Religion (Muslim or Non-Muslim): ";
        cin >> religion;

        cout << "Status (S - Single, M - Married, J - Single Mother, P - Single Parent): ";
        cin >> status;

        if (status == "M" || status == "J") {
            cout << "Number of children: ";
            cin >> numChildren;

            // Limit the number of children to the maximum limit
            numChildren = min(numChildren, maxChildLimit);

            // Calculate child rebate
            totalRebate = totalRebate + childRebate * numChildren;
        }

        // Calculate taxable income
        cout << "Yearly income: RM";
        cin >> taxableIncome;

        // Deduct the rebates
        if (gender == "M" && (status == "M" || status == "J"))
            taxableIncome = taxableIncome - ownSelfRebate;
        if (status == "M")
            taxableIncome -= wifeRebate;
        else if (status == "S")
            taxableIncome = taxableIncome - ownSelfRebate;
        taxableIncome = taxableIncome - totalRebate;

        // Calculate income tax
        double incomeTax = calculateIncomeTax(taxableIncome);

        if (religion == "Muslim") {
        
        zakatPaid = incomeTax * 0.025;
        
            cout << "Zakat paid: RM";
            cout << zakatPaid  << endl;
            
            incomeTax = incomeTax - zakatPaid;
        }

        if (incomeTax < 0)
            incomeTax = 0;

        incomeTaxArray[i] = incomeTax;

        cout << "Income Tax: RM" << incomeTax << endl;
        cout << endl;
    }

    // Calculate total income tax for all employees
    double totalIncomeTax = calculateTotalIncomeTax(incomeTaxArray, numEmployees);

    cout << "Total Income Tax for all employees: RM" << totalIncomeTax << endl;

    // Calculate the amount gained by LHDN
    double amountGained = totalIncomeTax;

    if (amountGained < 0)
        amountGained = 0;

    cout << "Amount gained by LHDN: RM" << amountGained << endl;

    // Calculate the amount to be returned to the income payer
    double amountToReturn = totalIncomeTax - amountGained;

    cout << "Amount to be returned to the income payer: RM" << amountToReturn << endl;

    return 0;
}
