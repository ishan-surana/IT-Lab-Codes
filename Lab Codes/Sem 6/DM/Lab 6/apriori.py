data = [["Milk", "Bread", "Butter"], ["Bread", "Butter"], ["Milk", "Bread", "Jam"], ["Milk", "Butter", "Bread"], ["Bread"], ["Butter", "Jam"]]
min_sup = 0.3
min_conf = 0.75
sup_count = min_sup*len(data)
all_items = []
for i in data:
    all_items.extend(i)
all_items = sorted(list(set(all_items)))
print("All unique items:", all_items)

def get_n_itemset(n, dataset):
    if n==1:
        return [[i] for i in dataset]
    n_minus_1_itemsets = get_n_itemset(n-1, dataset)
    n_itemsets = []
    for i in n_minus_1_itemsets:
        for j in all_items:
            if j > i[-1]:
                n_itemsets.append(i+[j])
    return n_itemsets

freq_itemsets = []
def apriori():
    for i in range(1, len(all_items)+1):
        print(f"\nFrequent {i}-itemsets")
        i_itemsets = get_n_itemset(i, all_items)
        for j in i_itemsets:
            count = sum([all([True if x in k else False for x in j]) for k in data])
            if count >= sup_count:
                freq_itemsets.append(j)
                print(j)

apriori()

def confidence(a, b):
    a_union_b = a + [x for x in b if x not in a]
    sup_a = sum([all(x in k for x in a) for k in data])
    sup_a_union_b = sum([all(x in k for x in a_union_b) for k in data])
    return sup_a_union_b / sup_a

def association_rules():
    print("\nAssociation rules:")
    for fi in freq_itemsets:
        if len(fi) > 1:
            antedecants = []
            for i in range(1, len(fi)):
                antedecants.extend(get_n_itemset(i, fi))
            for i in antedecants:
                diff = [x for x in fi if x not in i]
                if confidence(i, fi) >= min_conf:
                    print(list(i), "=>", diff)

association_rules()