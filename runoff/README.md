## Runoff

The program runs a runoff election, per the below.

Number of voters: 5

Rank 1: Alice, Rank 2: Bob, Rank 3: Charlie

Rank 1: Alice, Rank 2: Charlie, Rank 3: Bob

Rank 1: Bob, Rank 2: Charlie, Rank 3: Alice

Rank 1: Bob, Rank 2: Alice, Rank 3: Charlie

Rank 1: Charlie, Rank 2: Alice, Rank 3: Bob

Winner: Alice

## Background

In plurality elections, every voter gets one vote, and the candidate with the most votes wins. But the plurality vote does have some disadvantages. If two candidates have the same amount of votes, a plurality vote would here declare a tie between those two candidates.

There’s another kind of voting system known as a ranked-choice voting system. In a ranked-choice system, voters can vote for more than one candidate. Instead of just voting for their top choice, they can rank the candidates in order of preference. Each voter, in addition to specifying their first preference candidate, has also indicate their second and third choices. And now, what was previously a tied election could now have a winner.

Additionally, in a plurality vote where each voter chooses their first preference only, a candidate wins the election with four votes compared to only three for another candidate and two for a third candidate. But a majority of the voters (5 out of the 9) would be happier with the other candidates compared to the first place candidate. By considering ranked preferences, a voting system may be able to choose a winner that better reflects the preferences of the voters.

One such ranked choice voting system is the instant runoff system. In an instant runoff election, voters can rank as many candidates as they wish. If any candidate has a majority (more than 50%) of the first preference votes, that candidate is declared the winner of the election.

If no candidate has more than 50% of the vote, then an “instant runoff” occurrs. The candidate who received the fewest number of votes is eliminated from the election, and anyone who originally chose that candidate as their first preference now has their second preference considered. The process repeats: if no candidate has a majority of the votes, the last place candidate is eliminated, and anyone who voted for them will instead vote for their next preference (who hasn’t themselves already been eliminated). Once a candidate has a majority, that candidate is declared the winner.

Should there be a tie for those who should get eliminated, all those candidates will be eliminated. If every remaining candidate has the exact same number of votes, though, eliminating the tied last place candidates means eliminating everyone! So in that case, we do not to eliminate everyone, and just declare the election a tie between all remaining candidates.


Reference: https://cs50.harvard.edu/x/2021/psets/3/runoff/
