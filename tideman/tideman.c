#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }
          
        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();

    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{   
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;  
        }
    }

    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
            //printf("pref: %i \n", preferences[ranks[i]][ranks[j]]);
        }     
    }
    return;
}


// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++; 
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }     
    }
    return;
}


// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
 
    for (int i = 0; i < pair_count - 1; i++)
    {

        for (int j = i + 1; j < pair_count; j++)
        {
            if (preferences[pairs[j].winner][pairs[j].loser] < preferences[pairs[j + 1].winner][pairs[j + 1].loser])
            {                
                //sort by pair
                pair temp = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = temp; 
            }
        }
    }

    return;
}



//Goal: iterate through all the locked candidates loser has won against
//check if any of these are circle start, to prevent locking into circle start, causing a cycle 
bool isCycle(int cycle_start, int loser)
{
    if (loser == cycle_start)
    {
        return true;
    }
    
    for (int i = 0; i < candidate_count; i++)
    {
        //Check who has loser won against
        if (locked[loser][i])
        {
            //Has he won against someone that is a cicle start?
            if (isCycle(cycle_start, i))
            {
                return true; 
            }
        }
    }

    return false;
}

void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        if (!isCycle(pairs[i].winner, pairs[i].loser))
        {
            // Lock the pair
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    
    return;
}


// Print the winner of the election
void print_winner(void)
{   
    for (int i = 0; i < candidate_count; i++)
    {   
        //Reset false value for every candidate i
        int false_value = 0;

        for (int j = 0; j < candidate_count; j++)
        {
            //Check if j is pointing to i (if false, then its not)
            if (locked[j][i] == false)
            {
                false_value++; 

                //Which candidate has the least amount of pointers pointing to it (fewest locked pairs). Winner should not have any pointers pointing to it. 
                if (false_value == candidate_count)
                {
                    printf("Winner: %s \n", candidates[i]);
                }
            }
        }  
    }


    return;
}

