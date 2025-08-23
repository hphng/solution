class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack = []
        for item in asteroids:
            while stack and item < 0 < stack[-1]:
                if -item > stack[-1]:
                    stack.pop()
                    continue
                elif -item == stack[-1]:
                    stack.pop()
                break
            else:
                stack.append(item)
        return stack