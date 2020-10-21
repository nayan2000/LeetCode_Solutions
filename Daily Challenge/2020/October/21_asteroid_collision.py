class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        res = []

        for x in asteroids:
            # does it collide?
            # Inside the while loop there will be a colission
            while len(res) and x < 0 and res[-1] > 0:
                # Both have same maghnitude so they both break
                if (res[-1] + x) == 0:
                    res.pop()
                    break

                # Incoming asteroid breaks
                elif abs(x) < res[-1]:
                    break

                # top asteroid in stack breaks
                else:
                    res.pop()
                    continue
            else:
                # appending asteroid to res
                res.append(x)

        return res
