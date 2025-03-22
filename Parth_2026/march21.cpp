class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            unordered_set<string> availableSupplies ;
            unordered_map<string,int>  recipeToIndex ;
            //ingredient -> {recipes where it is needed}
            unordered_map<string,vector<string>> dependencyGraph ;
    
            for(auto& supply : supplies){
                availableSupplies.insert(supply) ;
            }
            for(int i = 0 ;i<recipes.size() ;i++){
                recipeToIndex[recipes[i]] = i ;
            }
            vector<int> indegree(recipes.size(),0) ;
            for(int recipeIdx = 0 ;recipeIdx < recipes.size(); recipeIdx ++){
                for(string& ingredient : ingredients[recipeIdx]){
                    if(!availableSupplies.count(ingredient)){
                        dependencyGraph[ingredient].push_back(recipes[recipeIdx]) ;
                        indegree[recipeIdx]++ ;
                    }
                }
            }
    
            queue<int> q ;
            for(int recipeIdx = 0 ;recipeIdx < recipes.size() ; recipeIdx++){
                if(indegree[recipeIdx]==0){
                    q.push(recipeIdx) ;
                }
            }
            vector<string> created ;
            while(!q.empty()){
                int recipeIdx = q.front() ;
                q.pop() ;
                string recipe = recipes[recipeIdx] ;
                created.push_back(recipe);
    
                if(!dependencyGraph.count(recipe))  continue ;
                for(string& dependentRecipe : dependencyGraph[recipe]){
                    if(--indegree[recipeToIndex[dependentRecipe]]==0){
                        q.push(recipeToIndex[dependentRecipe]) ;
                    }
                }
            }
            return created ;
        }
    };