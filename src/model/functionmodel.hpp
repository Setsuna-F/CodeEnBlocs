#ifndef FUNCTIONMODEL_HPP
#define FUNCTIONMODEL_HPP

#include <string>
#include <vector>
#include "variablemodel.hpp"
#include "blockcompositemodel.hpp"
#include "tools.h"

namespace satap{

	class FunctionModel : public BlockCompositeModel{

		public:
			FunctionModel(std::string name, std::vector<BlockCompositeModel*> blockList);
			FunctionModel(std::string name, std::vector<BlockCompositeModel*> blockList, std::vector<VariableModel> parameterList);
		virtual BlockModel* getBlockById(size_t id){
			//std::cout<<"r0"<<std::endl;
			
			if (id==this->getId()){
				//std::cout<<"r1"<<std::endl;
				return this;
			}
			//std::cout<<"L'id"<<"="<<id<<std::endl;
			
			BlockModel *block=nullptr;
			/*for (std::vector<BlockModel *>::iterator it = this->_blockList.begin(); it != this->_blockList.end(); ++it){
				std::cout<<(*it)->getId()<<"="<<id<<std::endl;
				
				if ((*it)->getId() == id){
			 std::cout<<"r2"<<std::endl;
			 return *it;
				}
				else{
			 std::cout<<"r3 "<< (*it)->strstr()<<std::endl;
			 block = (*it)->getBlockById(id);
				}
			 }*/
			//std::cout<<"r4"<<std::endl;
			return block;
		}
			//TODO : constructor with any number of variables and at least one block, automatically detects what is a variable and what is a block
		
			sct_type execute();

		private:
			//name
			std::string _name;

			//parameters
			std::vector<VariableModel> _parameterList;

			//block list
			std::vector<BlockCompositeModel*> _blockList;

	};

}

#endif
