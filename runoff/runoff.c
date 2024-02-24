#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Checa se vc iniciou o script e colocou os nomes ./runoff Alice Charlie Bob
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Mantém consultando os eleitores
    for (int i = 0; i < voter_count; i++)
    {

        // Consulta por rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Vê se o voto foi válido
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calcula os votos dos candidatos
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Se o voto for válido ele faz o rank
bool vote(int voter, int rank, string name)
{
    int c = 0;
    for (int j = 0; j < candidate_count; j++)
    {
        if (strcmp(candidates[j].name,name) == 0)
        {
            preferences[voter][rank] = c;
            return true;
        }
        c += 1;
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
// Alterar candidates.votes com alguma repetição em preferences
void tabulate(void)
{
    for (int c = 0; c < voter_count;c++)
    {
        int i = 0;

        for (int _ = 0; _ < candidate_count; _++)
        {
            if (candidates[preferences[c][i]].eliminated == false)
            {
                candidates[preferences[c][i]].votes += 1;
                break;
            }
            else
            {
                i++;
            }
        }

    }

// candidates[i].votes += preferences[c][i]
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    for (int c = 0; c < candidate_count; c++)
    {
        if (candidates[c].votes > (voter_count / 2))
        {
            printf("%s\n",candidates[c].name);
            return true;
        }
    }
    return false;

}


int find_min(void)
{
    int min = candidates[0].votes;
    for (int c = 0; c < candidate_count; c++)
    {
        if (candidates[c].votes <= min && candidates[c].eliminated == false)
        {
            min = candidates[c].votes;
        }
    }

    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    int i = 0;
    int count = 0;
    for (int c = 0,sum = 0; c < candidate_count; c++)
    {
        if (candidates[c].eliminated == false)
        {
            count++;
        }
        if (candidates[c].votes == min && candidates[c].eliminated == false)
        {
            i++;
        }
    }
    if (i == count)
    {
        return true;
    }
    else
    {
        return false;
    }

}


void eliminate(int min)
{
    for (int c = 0; c < candidate_count; c++)
    {
        if (candidates[c].votes == min)
        {
            candidates[c].eliminated = true;
        }
    }
    return;
}