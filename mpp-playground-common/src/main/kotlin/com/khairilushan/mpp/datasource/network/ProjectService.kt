package com.khairilushan.mpp.datasource.network

class ProjectService(endpoint: Int) : NetworkService() {

  companion object {
    const val SEARCH = 0
    const val DETAIL = 1
  }

  override val path = when (endpoint) {
    ProjectService.SEARCH -> "/search/repositories"
    ProjectService.DETAIL -> ""
    else -> throw IllegalArgumentException("Undefined endpoint $endpoint for ProjectService")
  }
}