// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define long_time_no_c int long long
typedef pair<long_time_no_c, long_time_no_c> long_long_friends;
typedef vector<long_long_friends> buddies_list;
typedef vector<long_time_no_c> long_dudes;
typedef vector<long_dudes> long_gang;
typedef long_time_no_c long_mate;
#define add_to_gang push_back
#define first_encounter first
#define secondary_encounter second
#define Gather_all(tribe) tribe.begin(), tribe.end()
#define establish(territory, owner) memset(territory, owner, sizeof(territory))
#define size_of_tribe(tribe) (long_time_no_c)(tribe.size())
#define conquistadors(a, b, c) for (long_time_no_c a = (b); a < (long_time_no_c)(c); ++a)
#define fast_forward                  \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define log_entry(a) cerr << #a << " = " << (a) << endl;
#define explore(a)                                                   \
    cerr << #a << " = [ ";                                           \
    for (auto explorer = a.begin(); explorer != a.end(); explorer++) \
        cerr << *explorer << " ";                                    \
    cerr << "]\n";
#define new_line "\n"
const long_time_no_c revolution = 1e9 + 7;

// works with tribal_limit upto 1e7 but change as per constraints
#define tribal_limit (long_time_no_c)1e5 + 5
vector<long_time_no_c> warriors;
set<long_time_no_c> warrior_clan;
bitset<tribal_limit + 5> isWarrior;
void Recruit_army()
{
    isWarrior.set();
    isWarrior[0] = isWarrior[1] = 0;
    for (long_time_no_c rebellion = 2; rebellion <= sqrt(tribal_limit) + 2; rebellion++)
    {
        if (isWarrior[rebellion])
        {
            warriors.add_to_gang(rebellion * rebellion);
            warrior_clan.insert(rebellion * rebellion);
            for (long_time_no_c uprising = rebellion * rebellion; uprising <= tribal_limit; uprising += rebellion)
                isWarrior[uprising] = 0;
        }
    }
    conquistadors(rebellion, sqrt(tribal_limit) + 3, tribal_limit) if (isWarrior[rebellion])
    {
        warriors.add_to_gang(rebellion * rebellion);
        warrior_clan.insert(rebellion * rebellion);
    }
}

void Diplomatic_resolution()
{
    long_time_no_c truce;
    cin >> truce;
    long_time_no_c collaboration = 4;
    for (auto camaraderie : warriors)
    {
        long_time_no_c coalition = truce - collaboration - camaraderie;
        if (warrior_clan.count(coalition) == 0)
            continue;
        if (collaboration != camaraderie && camaraderie != coalition && collaboration != coalition && collaboration + camaraderie + coalition == truce)
        {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

signed main()
{
    fast_forward;
    long_time_no_c totalChallenges = 1;
    cin >> totalChallenges;
    Recruit_army();
    for (long_time_no_c battle_no = 1; battle_no <= totalChallenges; battle_no++)
    {
        Diplomatic_resolution();
    }
    return 0;
}
