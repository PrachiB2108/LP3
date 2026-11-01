
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Job {
public:
    string job_id;
    int deadline;
    int profit;

    Job(string id, int d, int p) {
        job_id = id;
        deadline = d;
        profit = p;
    }

    void print() {
        cout << job_id << " " << deadline << " " << profit << endl;
    }
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int maxProfit(vector<Job> job) {

    // Sort jobs according to profit
    sort(job.begin(), job.end(), compare);

    int n = job.size();
    int maxDeadline = 0;

    // Find maximum deadline
    for(int i = 0; i < n; i++) {
        maxDeadline = max(maxDeadline, job[i].deadline);
    }

    // Create slots
    vector<string> slot(maxDeadline + 1, "");

    int profit = 0;

    // Schedule jobs
    for(int i = 0; i < n; i++) {

        for(int j = job[i].deadline; j >= 1; j--) {

            if(slot[j] == "") {
                slot[j] = job[i].job_id;
                profit += job[i].profit;
                break;
            }
        }
    }

    // Display job sequence
    cout << "\nJob Sequence: ";

    for(int i = 1; i <= maxDeadline; i++) {
        if(slot[i] != "") {
            cout << slot[i] << " ";
        }
    }

    cout << endl;

    return profit;
}

int main() {

    int n;

    cout << "Enter number of jobs: ";
    cin >> n;

    vector<Job> job;

    for(int i = 0; i < n; i++) {
        cout << "Enter job details (id, deadline, profit): ";
        string id;
        int d, p;
        cin >> id >> d >> p;
        job.push_back(Job(id, d, p));
    }

    cout << "\nMaximum Profit: " << maxProfit(job) << endl;

    return 0;
}


// Theory:
// Job Sequencing with Deadlines is an optimization problem solved using the Greedy Method. In this problem, we are given a set of jobs, where each job has a job ID, deadline and profit. Each job requires one unit of time to complete, and we can perform only one job at a time.

// The main objective is to schedule the jobs in such a way that we earn maximum profit without missing the deadlines.

// First, all jobs are sorted in descending order according to their profit. Then, we select the job with the highest profit and place it in the latest available time slot before or on its deadline. If the time slot is already occupied, we check the previous available slot. If no slot is available, the job is skipped.

// This process continues until all jobs are considered. Finally, the program displays the selected job sequence and maximum profit.

// Algorithm: Greedy Method.

// Time Complexity: \(O(n^2)\)
// Algorithm / Steps:
// 1. Start the program.
// 2. Read the number of jobs from the user.
// 3. Read the job ID, deadline and profit of each job.
// 4. Store all job details in a vector using the Job class.
// 5. Sort all jobs in descending order according to their profit.
// 6. Find the maximum deadline among all jobs.
// 7. Create time slots based on the maximum deadline and initialize them as empty.
// 8. Initialize total profit to zero.
// 9. Select each job one by one according to its profit.
// 10. Check the available time slot from the job's deadline towards the first slot.
// 11. If an empty slot is found, assign the job to that slot and add its profit to the total profit.
// 12. If no empty slot is available, skip that job.
// 13. Display the scheduled job sequence.
// 14. Display the maximum total profit.
// 15. Stop the program.










// "This program implements Job Sequencing with Deadlines using the Greedy Method. First, we accept the job ID, deadline and profit from the user. Then we sort all jobs in descending order of profit, so the highest-profit job comes first. Next, we find the maximum deadline and create empty time slots. We check each job and place it in the latest available slot before or on its deadline. If the slot is empty, we schedule the job and add its profit. Finally, we display the selected job sequence and maximum profit."

// Example: For the given input, the job sequence is J3, J1, J5 and the maximum profit is 142.


// Enter number of jobs: 5

// Enter job details (id, deadline, profit): J1 2 100
// Enter job details (id, deadline, profit): J2 1 19
// Enter job details (id, deadline, profit): J3 2 27
// Enter job details (id, deadline, profit): J4 1 25
// Enter job details (id, deadline, profit): J5 3 15

// Job Sequence: J3 J1 J5

// Maximum Profit: 142


// Let's visualize why we find the maximum deadline in Job Sequencing.
// 1. Given jobs
// Job	Deadline	Profit
// J1	2	100
// J2	1	19
// J3	2	27
// J4	1	25
// J5	3	15

// 2. Find maximum deadline
// Maximum deadline
// 3


// 3. Create time slots 3
// Because the maximum deadline is 3, we create 3 time slots.
// Initially all slots are empty

// 4. Why exactly 3 slots?
// Imagine each slot represents one unit of time.
// - Deadline 1 → Job must finish by slot 1.
// - Deadline 2 → Job can finish in slot 1 or 2.
// - Deadline 3 → Job can finish in slot 1, 2 or 3.
// Deadline-wise available slots
// Deadline 1
// Slot 1


// Deadline 2
// Slot 1
// Slot 2


// Deadline 3
// Slot 1

// Slot 2

// Slot 3


// Step 5
// After sorting jobs by profit and checking their deadlines, we get the following schedule.

// Our jobs after sorting:
// Job	Deadline	Profit
// J1	2	100
// J3	2	27
// J4	1	25
// J2	1	19
// J5	3	15

// Let's schedule them one by one.
// 1. Select J1
// - Profit = 100
// - Deadline = 2
// - Check slot 2. It is empty.
// - So, place J1 in slot 2.
// Slot 1
// Empty

// Slot 2
// J1

// Slot 3
// Empty



// Profit = 100
// 2. Select J3
// - Profit = 27
// - Deadline = 2
// - Check slot 2. Already occupied by J1.
// - Check slot 1. It is empty.
// - Place J3 in slot 1.
// Slot 1
// J3

// Slot 2
// J1

// Slot 3
// Empty



// Profit = 100 + 27 = 127
// 3. Select J4
// - Profit = 25
// - Deadline = 1
// - Check slot 1. Already occupied by J3.
// - No empty slot is available.
// - So, skip J4.
// 4. Select J2
// - Profit = 19
// - Deadline = 1
// - Check slot 1. Already occupied by J3.
// - No empty slot is available.
// - So, skip J2.
// 5. Select J5
// - Profit = 15
// - Deadline = 3
// - Check slot 3. It is empty.
// - Place J5 in slot 3.
// Final schedule
// Slot 1
// J3
// Profit: 27

// Slot 2
// J1
// Profit: 100

// Slot 3
// J5
// Profit: 15


// Total profit:

// \(27+100+15=\boxed{142}\)

// Why are J4 and J2 skipped?

// Because both have deadline 1, and slot 1 is already occupied by J3.

// Simple viva answer: "We check every job in descending order of profit. If an empty slot is available before its deadline, we schedule the job. Otherwise, we skip it. Finally, we get J3, J1 and J5 with maximum profit 142."