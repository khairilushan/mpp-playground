package com.khairilushan.mpp.viewmodel

import com.khairilushan.mpp.interactor.Result
import com.khairilushan.mpp.interactor.SearchProjectInteractor
import com.khairilushan.mpp.interactor.createSearchProjectInteractor

interface SearchProjectViewModel {
    interface Inputs : ViewModel.Inputs {
        fun onSearchButtonClicked()
        fun onSearchTextFieldChanged(text: String)
    }

    interface Outputs {
        fun startLoading()
        fun finishLoading()
        fun shouldUpdateData(data: List<ProjectItemViewModel>)
        fun shouldDismissKeyboard()
        fun showErrorMessage(message: String)
    }
}

val DEFAULT_KEYWORD = "kotlin"

class SearchProjectViewModelImpl(
    private val outputs: SearchProjectViewModel.Outputs
) : BaseViewModel(), SearchProjectViewModel.Inputs {

    private var keyword = DEFAULT_KEYWORD
    private val interactor: SearchProjectInteractor by lazy { createSearchProjectInteractor() }

    override fun onViewCreated() {
        requestProductList()
    }

    override fun onSearchButtonClicked() {
        if (keyword.isEmpty()) return
        requestProductList()
        outputs.shouldDismissKeyboard()
    }

    override fun onSearchTextFieldChanged(text: String) {
        keyword = text
    }

    private fun requestProductList() {
        outputs.startLoading()
        val params = SearchProjectInteractor.Params(keyword)
        interactor.execute(params) { result ->
            outputs.finishLoading()
            when (result) {
                is Result.Success -> {
                    outputs.shouldUpdateData(result.result.map { it.mapToViewModel() })
                }
                is Result.Failure -> {
                    outputs.showErrorMessage(result.message)
                }
            }
        }
    }
}
