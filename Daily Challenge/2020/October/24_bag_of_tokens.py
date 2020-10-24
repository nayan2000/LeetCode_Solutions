'''
Initially, your score is 0: If tokens is empty or least value in tokens is more than P, then you cant increase your score so return 0
Sort the tokens and put them in a queue.
The core algorithm:
If tokens is empty at any point: return the current score
If the least value in tokens is more than current Power:
- If score is 0, then return 0 as you cant increase your score
- If score is non zero:
- If the tokens only has one element, then return as it will just decrease the score
- Else: add max value of tokens to Power and decrease score by 1.
If the least value in tokens is <= current Power:
You can always increase your score in this case:
Starting from start of tokens(i.e. min value -> max value) until this value<=currentPower:
Decrease this value from P and keep incrementing score.
'''
class Solution:
    def bagOfTokensScore(self, tokens: List[int], P: int) -> int:
        # print(f'TC: {tokens}, {P}')
        if not tokens:
            return 0
        tokens = collections.deque(sorted(tokens))
        if tokens[0]>P:
            return 0
        score = 0
        while True:
            if not tokens:
                return score
            if tokens[0]>P:
                if not score:
                    return score
                else:
                    if len(tokens)>1:
                        P+=tokens[-1]
                        score-=1
                        tokens.pop()
                    else:
                        return score                
            else:
                while tokens and tokens[0]<=P:
                    P-=tokens[0]
                    score+=1
                    tokens.popleft()
        return score