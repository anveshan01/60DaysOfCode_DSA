class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            //storing available supplies
            unordered_set<string>availableSupplies;
    
            //storing recipes and index
            unordered_map<string ,int>recipeIndex;
    
            //map ingredient to recipes
            unordered_map<string,vector<string>>dependencyGraph;
            //available supplies
            for(string& supply:supplies){
                availableSupplies.insert(supply);
            }
            //recipe to index
            for(int i=0;i<recipes.size();i++){
                recipeIndex[recipes[i]]=i;
            }
            //count of non-supply ingredient needed for recipe
            vector<int>inDegree(recipes.size(),0);
            //dependency array
            for(int i=0;i<recipes.size();i++){
                for(string & ingredient:ingredients[i]){
                    if(!availableSupplies.count(ingredient)){
                        //add edge: ingre->recipe
                        dependencyGraph[ingredient].push_back(recipes[i]);
                        inDegree[i]++;
                    }
                }
            }
            //recipe that only need supply
            queue<int>q;
            for(int i=0;i<recipes.size();i++){
                if(inDegree[i]==0){
                    q.push(i);
                }
            }
            //recipes in topological order
            vector<string>createdrecipes;
            while(!q.empty()){
                int recipeindex=q.front();
                q.pop();
                string recipe=recipes[recipeindex];
                createdrecipes.push_back(recipe);
                //skip if no recipes depend on this
                if(!dependencyGraph.count(recipe)) continue;
                //update recipes that depend on this
                for(string &dependRecipe:dependencyGraph[recipe]){
                    if(--inDegree[recipeIndex[dependRecipe]]==0){
                        q.push(recipeIndex[dependRecipe]);
                    }
                }
            }
            return createdrecipes;
            
        }
    };