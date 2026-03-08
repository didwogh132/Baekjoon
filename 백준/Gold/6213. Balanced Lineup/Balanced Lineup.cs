using System;
using System.IO;
using System.Text;

public struct node
{
    public int Minidx;
    public int Maxidx;

    public node(int minidx, int maxidx)
    {
        Minidx = minidx;
        Maxidx = maxidx;
    }
}

public class SegmentTree
{
    private int[] arr;
    private node[] tree;
    private int n;

    public SegmentTree(int[] input)
    {
        arr = input;
        n = input.Length;
        tree = new node[n * 4];
        build(1, 0, n - 1);
    }

    private node merge(node left, node right)
    {
        if (left.Minidx == -1) return right;
        if (right.Minidx == -1) return left;

        int minidx;
        int maxidx;

        if (arr[left.Minidx] <= arr[right.Minidx])
        {
            minidx = left.Minidx;
        }
        else
        {
            minidx = right.Minidx;
        }

        if (arr[left.Maxidx] >= arr[right.Maxidx])
        {
            maxidx = left.Maxidx;
        }
        else
        {
            maxidx = right.Maxidx;
        }

        return new node(minidx, maxidx);
    }

    private node build(int node, int start, int end)
    {
        if(start == end)
        {
            tree[node] = new node(start, start);
            return tree[node];
        }

        int mid = (start + end) / 2;
        node left = build(node * 2, start, mid);
        node right = build(node * 2 + 1, mid + 1, end);

        tree[node] = merge(left, right);
        return tree[node];
    }

    public node query(int left, int right)
    {
        return query(1, 0, n - 1, left, right);
    }

    public node query(int node, int s, int e, int left, int right)
    {
        if(right < s || left > e)
        {
            return new node(-1, -1);
        }

        if(left <= s && e <= right)
        {
            return tree[node];
        }

        int mid = (s + e) / 2;
        node leftresult = query(node * 2, s, mid, left, right);
        node rightresult = query(node * 2 + 1, mid + 1, e, left, right);

        return merge(leftresult, rightresult);
    }
}

public class Program
{
    public static void Main()
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StringBuilder sb = new StringBuilder();

        string[] first = sr.ReadLine().Split();
        int n = int.Parse(first[0]);
        int q = int.Parse(first[1]);

        int[] arr = new int[n];

        for(int i =0; i < n; i++)
        {
            arr[i] = int.Parse(sr.ReadLine());
        }

        SegmentTree segtree = new SegmentTree(arr);

        for(int i =0; i < q; i++)
        {
            string[] input = sr.ReadLine().Split();
            int left = int.Parse(input[0]) - 1;
            int right = int.Parse(input[1]) - 1;

            node result = segtree.query(left, right);
            int answer = arr[result.Maxidx] - arr[result.Minidx];
            sb.Append(answer).Append("\n");
        }

        Console.Write(sb.ToString());
    }
}