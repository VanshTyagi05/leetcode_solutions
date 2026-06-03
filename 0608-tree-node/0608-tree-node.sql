SELECT id,
   CASE 
      WHEN p_id IS NULL THEN 'Root'
      -- 1. Removed 'p_id' (should check 'id') and removed 'is'
      -- 2. Changed 'as' to 'then'
      WHEN id IN (SELECT p_id FROM Tree) THEN 'Inner'
      ELSE 'Leaf'
   END AS type
FROM Tree;
