import math

with open("diabetes.csv", "r") as f:
    keys = f.readline().strip().split(",")
    data = {}
    for k in keys:
        data[k] = []
    while True:
        dataline = f.readline().strip().split(",")
        if dataline == ['']:
            break
        dataline = [float(i) for i in dataline]
        for v, c in zip(dataline, keys):
            data[c].extend([v])

col_names = list(data.keys())
col_names.remove('Outcome')

def prob(features, values, outcome):
    total_prob = 1
    for feature, value in zip(features, values):
        priors = [i for i, j in zip(data[feature], data['Outcome']) if j == outcome]
        mean = sum(priors) / len(priors)
        var = sum([(i - mean) ** 2 for i in priors]) / (len(priors) - 1)
        total_prob *= (1 / (math.sqrt(2 * math.pi * var))) * math.exp(-((value - mean) ** 2) / (2 * var))
    outcome_prob = len([out for out in data['Outcome'] if out == outcome]) / len(data['Outcome'])
    return total_prob * outcome_prob

def predict(features, values):
    probs = [prob(features, values, outcome) for outcome in [0, 1]]
    return 1 if probs[1] > probs[0] else 0

def evaluate():
    y_true = data['Outcome']
    y_pred = [predict(col_names, [data[f][i] for f in col_names]) for i in range(len(y_true))]
    
    accuracy = sum([1 if y_true[i] == y_pred[i] else 0 for i in range(len(y_true))]) / len(y_true)
    
    tp = sum([1 if y_true[i] == 1 and y_pred[i] == 1 else 0 for i in range(len(y_true))])
    fp = sum([1 if y_true[i] == 0 and y_pred[i] == 1 else 0 for i in range(len(y_true))])
    fn = sum([1 if y_true[i] == 1 and y_pred[i] == 0 else 0 for i in range(len(y_true))])
    
    precision = tp / (tp + fp) if tp + fp > 0 else 0
    recall = tp / (tp + fn) if tp + fn > 0 else 0
    
    return accuracy, precision, recall

accuracy, precision, recall = evaluate()
print(f"Accuracy: {accuracy:.4f}")
print(f"Precision: {precision:.4f}")
print(f"Recall: {recall:.4f}")