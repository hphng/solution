class Solution:
    def bestClosingTime(self, customers: str) -> int:
        best_hour = -1
        score = max_score = 0
        #check current index is close
        for i, c in enumerate(customers):
            if c == "Y":
                score += 1
            if c == "N":
                score -= 1
            if max_score < score:
                max_score, best_hour = score, i
        return best_hour + 1

