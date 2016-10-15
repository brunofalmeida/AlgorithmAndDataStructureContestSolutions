def getWinner (SA, SB):
    ''' 1 - A wins
        -1 - B wins
        0 - tie'''
    if SA > SB:
        return 1
    elif SB > SA:
        return -1
    else:
        return 0

def update_game (scores, games, A, B, SA, SB):
    games.remove ( (A, B) )
    
    winner = getWinner (SA, SB)
    if winner == 1:
        scores [A] += 3
    elif winner == -1:
        scores [B] += 3
    else:
        scores [A] += 1
        scores [B] += 1

def update (scores, games):
    global wins, T

    if len (games) == 0:
        scores_temp = scores [:]
        scores_temp.sort ()
        if scores [T] == scores_temp [-1] and scores_temp [-2] != scores_temp [-1]:
            wins += 1

    else:
        scores_temp = scores [:]
        games_temp = games [:]
        update_game (scores_temp, games_temp, games_temp [0] [0], games_temp [0] [1], 0, 0)
        update (scores_temp, games_temp)

        scores_temp = scores [:]
        games_temp = games [:]
        update_game (scores_temp, games_temp, games_temp [0] [0], games_temp [0] [1], 0, 1)
        update (scores_temp, games_temp)

        scores_temp = scores [:]
        games_temp = games [:]
        update_game (scores_temp, games_temp, games_temp [0] [0], games_temp [0] [1], 1, 0)
        update (scores_temp, games_temp)
            
        

scores = [0 for i in xrange (5)]
games = [ (1, 2), (1, 3), (1, 4), (2, 3), (2, 4), (3, 4) ]
wins = 0

T = int (raw_input () )
G = int (raw_input () )

for i in range (G):
    A, B, SA, SB = map (int, raw_input ().split () )
    update_game (scores, games, A, B, SA, SB)

update(scores, games)
print wins
