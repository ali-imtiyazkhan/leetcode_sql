class Solution:
    def assignEdgeWeights(self, edges):
        MOD = 10**9 + 7
        n = len(edges) + 1

        if n == 1:
            return 0

        g = [[] for _ in range(n + 1)]
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)

        depth = 0
        stack = [(1, 0, 0)]

        while stack:
            node, parent, d = stack.pop()
            depth = max(depth, d)

            for nei in g[node]:
                if nei != parent:
                    stack.append((nei, node, d + 1))

        return pow(2, depth - 1, MOD)